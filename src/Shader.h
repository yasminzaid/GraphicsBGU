#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <Debugger.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader
{
    private:
        std::string m_Filepath;
        unsigned int m_RendererID;
        std::unordered_map<std::string, int> m_UniformLocationCache;
    public:
        Shader(const std::string& filepath);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        // Set uniforms
        void SetUniform1i(const std::string& name, int value);
        void SetUniform1f(const std::string& name, float value);
        void SetUniform4f(const std::string& name, glm::vec4& value);
        void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
    private:
        ShaderProgramSource ParseShader(const std::string& filepath);
        unsigned int CompileShader(unsigned int type, const std::string& source);
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

        int GetUniformLocation(const std::string& name);
};