#version 130

precision highp float;
uniform vec4 color;

void main()
{
    gl_FragColor = color;
}