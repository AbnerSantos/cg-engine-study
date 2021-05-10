/* para linux, instalar os pacotes libglfw3-dev mesa-common-dev libglew-dev */
/* para compilar no linux: gcc main.c -lglfw -lGL -lGLEW -lm */

/* para windows, instalar bibliotecas compiladas do glfw3 e glew no ambiente mingw */
/* para compilar no windows: gcc main.c -lglfw3dll -lglew32 -lopengl32 */


#include <GL/glew.h>  

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h> /* verifique no seu SO onde fica o glfw3.h */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <ctime>
#include <chrono>

#include "Vector2.hpp"
#include "Shapes.hpp"
#include "Color.hpp"
#include "Matrix4x4.hpp"
#include "Renderer.hpp"

int TriangleScale(GLFWwindow*, Renderer, int, GameObject*);
int SquareRotate(GLFWwindow*, Renderer, int, GameObject*);
int CircleTranslate(GLFWwindow*, Renderer, int, GameObject*);
int TwoObjects(GLFWwindow*, Renderer, int, GameObject*, GameObject*);
int AllTransforms(GLFWwindow*, Renderer, int, GameObject*);

float deltaTime;

int currentPart = 0;
int currentIndex = 0;
int endIndex = 0;

void NextQuestion(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
    {
        currentPart++;
        currentIndex = endIndex;
        std::cout << currentIndex;
    }
}

char * ParseFile(std::string fileName)
{
    std::ifstream file(fileName);
    std::stringstream stream;
    stream << file.rdbuf();
    char * string = new char [stream.str().length()+1];
    strcpy (string, stream.str().c_str());
    file.close();
    return string;
}
 
int main(void)
{
    // Semente para o gerador aleatório
    srand (static_cast <unsigned> (time(0)));
 
    // inicicializando o sistema de\ janelas
    glfwInit();

    // deixando a janela invisivel, por enquanto
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

 
    // criando uma janela
    GLFWwindow* window = glfwCreateWindow(800, 800, "Ex2 - Aperte enter para ir para o próximo programa", NULL, NULL);

    
    // tornando a janela como principal 
    glfwMakeContextCurrent(window);

    // inicializando Glew (para lidar com funcoes OpenGL)
    GLint GlewInitResult = glewInit();
    printf("GlewStatus: %s", glewGetErrorString(GlewInitResult));

    // GLSL para Fragment Shader
    char * fragment_code = ParseFile("src/shaders/fragment/basic.fs");

    // GLSL para Vertex Shader
    char * vertex_code = ParseFile("src/shaders/vertex/transform.vs");

    // Requisitando slot para a GPU para nossos programas Vertex e Fragment Shaders
    GLuint program = glCreateProgram();
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    // Associando nosso código-fonte GLSL aos slots solicitados
    glShaderSource(vertex, 1, &vertex_code, NULL);
    glShaderSource(fragment, 1, &fragment_code, NULL);

    // Compilando o Vertex Shader e verificando erros
    glCompileShader(vertex);

    GLint isCompiled = 0;
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE){

        //descobrindo o tamanho do log de erro
        int infoLength = 512;
        glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &infoLength);

        //recuperando o log de erro e imprimindo na tela
        char info[infoLength];
        glGetShaderInfoLog(vertex, infoLength, NULL, info);

        printf("Erro de compilacao no Vertex Shader.\n");
        printf("--> %s\n",&info);

    }

    // Compilando o Fragment Shader e verificando erros
    glCompileShader(fragment);

    isCompiled = 0;
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE){

        //descobrindo o tamanho do log de erro
        int infoLength = 512;
        glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &infoLength);

        //recuperando o log de erro e imprimindo na tela
        char info[infoLength];
        glGetShaderInfoLog(fragment, infoLength, NULL, info);

        printf("Erro de compilacao no Fragment Shader.\n");
        printf("--> %s\n",&info);

    }

    // Associando os programas compilado ao programa principal
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);

    // Linkagem do programa e definindo como default
    glLinkProgram(program);
    glUseProgram(program);

    // Criando as formas
    Triangle triangleMesh = Triangle(Vector2::zero, 0.25f, 0.25f, Triangle::Type::Isosceles, Vector2(0.5f, 0.5f));
    Rectangle squareMesh = Rectangle(Vector2::zero, 0.35f, 0.35f);
    Circle circleMesh = Circle(Vector2::zero, 0.30f, 32);

    // Colorindo as formas
    triangleMesh.color = Color::orange;
    squareMesh.color = Color::purple;
    circleMesh.color = Color::cyan;

    // Criando os objetos
    GameObject triangle1 = GameObject();
    triangle1.AddShape(triangleMesh);

    GameObject square1 = GameObject();
    square1.AddShape(squareMesh);

    GameObject circle = GameObject();
    circle.AddShape(circleMesh);

    GameObject triangle2 = GameObject();
    triangle2.AddShape(triangleMesh);

    GameObject square2 = GameObject();
    square2.AddShape(squareMesh);

    GameObject triangle3 = GameObject();
    triangle3.AddShape(triangleMesh);

    // Obtendo todos os vértices
    std::vector<Vector2> v;

    std::vector<Vector2> triangle1Vertices = triangle1.GetVertices();
    std::vector<Vector2> square1Vertices = square1.GetVertices();
    std::vector<Vector2> circleVertices = circle.GetVertices();
    std::vector<Vector2> triangle2Vertices = triangle2.GetVertices();
    std::vector<Vector2> square2Vertices = square2.GetVertices();
    std::vector<Vector2> triangle3Vertices = triangle3.GetVertices();

    v.insert(v.end(), triangle1Vertices.begin(), triangle1Vertices.end());
    v.insert(v.end(), square1Vertices.begin(), square1Vertices.end());
    v.insert(v.end(), circleVertices.begin(), circleVertices.end());
    v.insert(v.end(), triangle2Vertices.begin(), triangle2Vertices.end());
    v.insert(v.end(), square2Vertices.begin(), square2Vertices.end());
    v.insert(v.end(), triangle3Vertices.begin(), triangle3Vertices.end());

    Vector2* vertices = v.data();

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    // Abaixo, nós enviamos todo o conteúdo da variável vertices.
    glBufferData(GL_ARRAY_BUFFER, v.size() * sizeof(Vector2), v.data(), GL_DYNAMIC_DRAW);

    // Associando variáveis do programa GLSL (Vertex Shaders) com nossos dados
    GLint loc = glGetAttribLocation(program, "position");
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void*) 0); // https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glVertexAttribPointer.xhtml
 
    // Criando renderizador e associando as variáveis de cor e transformação
    GLint locColor = glGetUniformLocation(program, "color");
    GLint locTransform = glGetUniformLocation(program, "mat_transformation");
    Renderer renderer = Renderer(locColor, locTransform);

    // Definindo que Enter vai fazer ir para a próxima questão
    glfwSetKeyCallback(window, NextQuestion);

    // Exibindo nossa janela
    glfwShowWindow(window);

    while (!glfwWindowShouldClose(window))
    {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0, 1.0, 1.0, 1.0);
        
        // Chama a parte adequada começando pela TriangleScale (ver funções abaixo)
        switch(currentPart)
        {
            case 0:
                endIndex = TriangleScale(window, renderer, currentIndex, &triangle1);
                break;

            case 1:
                endIndex = SquareRotate(window, renderer, currentIndex, &square1);
                break;

            case 2:
                endIndex = CircleTranslate(window, renderer, currentIndex, &circle);
                break;

            case 3:
                endIndex = TwoObjects(window, renderer, currentIndex, &triangle2, &square2);
                break;

            case 4:
                endIndex = AllTransforms(window, renderer, currentIndex, &triangle3);
                break;

            default:
                glfwSetWindowShouldClose(window, 1);
        }
 
        glfwSwapBuffers(window);

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        deltaTime = (float)std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0f;
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

int TriangleScale(GLFWwindow* window, Renderer renderer, int startIndex, GameObject* gameObject)
{
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
        gameObject->scale = gameObject->scale + Vector2(1.0f, 1.0f) * deltaTime;
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
        gameObject->scale = gameObject->scale - Vector2(1.0f, 1.0f) * deltaTime;

    return renderer.Draw(*gameObject, startIndex);
}

int SquareRotate(GLFWwindow* window, Renderer renderer, int startIndex, GameObject* gameObject)
{
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        gameObject->rotation += 30.0f * deltaTime;
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        gameObject->rotation -= 30.0f * deltaTime;

    return renderer.Draw(*gameObject, startIndex);
}

int CircleTranslate(GLFWwindow* window, Renderer renderer, int startIndex, GameObject* gameObject)
{
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        gameObject->position = gameObject->position + Vector2(0.0f, 1.0f) * deltaTime;
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        gameObject->position = gameObject->position + Vector2(0.0f, -1.0f) * deltaTime;
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        gameObject->position = gameObject->position + Vector2(-1.0f, 0.0f) * deltaTime;
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        gameObject->position = gameObject->position + Vector2(1.0f, 0.0f) * deltaTime;

    return renderer.Draw(*gameObject, startIndex);
}

int TwoObjects(GLFWwindow* window, Renderer renderer, int startIndex, GameObject* gameObject1, GameObject* gameObject2)
{
    gameObject1->scale = gameObject1->scale - Vector2(1.0f, 1.0f) * deltaTime;
    gameObject2->rotation += 30.0f * deltaTime;

    int index = renderer.Draw(*gameObject1, startIndex);
    return renderer.Draw(*gameObject2, index);
}

int AllTransforms(GLFWwindow* window, Renderer renderer, int startIndex, GameObject* gameObject)
{
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
        gameObject->scale = gameObject->scale + Vector2(1.0f, 1.0f) * deltaTime;
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
        gameObject->scale = gameObject->scale - Vector2(1.0f, 1.0f) * deltaTime;

    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        gameObject->rotation += 30.0f * deltaTime;
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        gameObject->rotation -= 30.0f * deltaTime;

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        gameObject->position = gameObject->position + Vector2(0.0f, 1.0f) * deltaTime;
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        gameObject->position = gameObject->position + Vector2(0.0f, -1.0f) * deltaTime;
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        gameObject->position = gameObject->position + Vector2(-1.0f, 0.0f) * deltaTime;
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        gameObject->position = gameObject->position + Vector2(1.0f, 0.0f) * deltaTime;

    return renderer.Draw(*gameObject, startIndex);
}