#version 330 core

out vec4 FragColor;
in vec4 color;

void main()
{
    FragColor=vec4(color.r, color.b, color.g, 1.f);
}