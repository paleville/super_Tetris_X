#include "actualGame.h"

float actualGame::time;
bool actualGame::gameOver = false; // Bandera de Game Over

// Initialization
actualGame::actualGame()
{
    // Inicialización de recursos, si es necesario
}

actualGame::~actualGame()
{
    // Liberación de recursos, si es necesario
}

bool actualGame::check()
{
    for (int i = 0; i < 4; i++)
    {
        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) // Límites del campo
        {
            return false;
        }
        else if (field[a[i].y][a[i].x]) // Límite de figuras
        {
            return false;
        }
    }
    return true;
}

void actualGame::loadFile()
{
    //startFirstFrame();
    update();
    draw();
}

void actualGame::resetGame()
{
    // Reiniciar el campo de juego
    memset(field, 0, sizeof(field));
    gameOver = false;
    timer = 0;

    // Generar una nueva pieza
    colorNum = 1 + rand() % 7;
    int n = rand() % 7;
    for (int i = 0; i < 4; i++)
    {
        a[i].x = figures[n][i] % 2;
        a[i].y = figures[n][i] / 2;
    }
}

void actualGame::update()
{
    if (gameOver) return; // No actualizar si es Game Over

    buttonClass::updateMousePosition();
    buttonClass::retryupdateButton(buttonClass::mousePosView);

    dx = 0; rotate = 0; delay = 0.3;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        std::cout << timer << std::endl;

        if (timer > 0.3)
        {
            rotate = true;
        }
        
    }
    else
    {
        clock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        dx = -1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        dx = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        delay = 0.05;
    }

    //// <- Move -> ///
    for (int i = 0; i < 4; i++)
    {
        b[i] = a[i];
        a[i].x += dx;
    }
    if (!check())
    {
        for (int i = 0; i < 4; i++)
        {
            a[i] = b[i]; // Detener movimiento
        }
    }

    //////Rotate//////
    if (rotate)
    {
        Point p = a[1]; // Centro de rotación
        for (int i = 0; i < 4; i++)
        {
            int x = a[i].y - p.y;
            int y = a[i].x - p.x;
            a[i].x = p.x - x;
            a[i].y = p.y + y;
        }
        if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
    }

    ///////Tick//////
    if (timer > delay)
    {
        for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }

        if (!check())
        {
            for (int i = 0; i < 4; i++)
            {
                if (b[i].y == 0) // Verificar si alguna pieza alcanza el tope
                {
                    music.openFromFile("Audio/gameOver.wav");
                    music.play();
                    gameOver = true; // Establecer la bandera de Game Over
                    return; // Salir de la actualización
                }
                field[b[i].y][b[i].x] = colorNum;
            }

            colorNum = 1 + rand() % 7;
            int n = rand() % 7;
            for (int i = 0; i < 4; i++)
            {
                a[i].x = figures[n][i] % 2;
                a[i].y = figures[n][i] / 2;
            }
        }

        timer = 0;
    }

    ///////check lines//////////
    int k = M - 1;
    for (int i = M - 1; i > 0; i--)
    {
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            if (field[i][j])
            {
                count++;
            }
            field[k][j] = field[i][j];
        }
        if (count < N)
        {
            k--;
        }
    }
}

void actualGame::draw()
{
    t1.loadFromFile("Images/tiles.png");
    t2.loadFromFile("Images/background.png");
    t3.loadFromFile("Images/frame01.png");

    s.setTexture(t1);


    background.setTexture(t2);
    background.setScale(0.76, 1);
    background.setPosition(30, 80);


    frame.setTexture(t3);
    frame.setScale(1.14, 1.4);
    frame.setPosition(-30, -55);

    // Initialize s_Vector with 24 elements
    s_Vector.assign(24, s);

    while (windowManager::getinstance().theWindow->isOpen())
    {
        time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        //std::cout << s_Vector.size() << std::endl;

        windowManager::getinstance().update();

        while (windowManager::getinstance().theWindow->pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
            {
                windowManager::getinstance().theWindow->close();
            }

            if (!check())
            {
                for (int i = 0; i < 4; i++)
                {
                    a[i] = b[i];
                }
            }
        }

        windowManager::getinstance().theWindow->clear(sf::Color::Cyan);
        windowManager::getinstance().theWindow->draw(background);

        for (int i = 0; i < M; i++) // Bottom draw
        {
            for (int j = 0; j < N; j++)
            {
                if (field[i][j] == 0)
                {
                    continue;
                }

                s_Vector[i].setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
                s_Vector[i].setScale(1.7, 1.7);
                s_Vector[i].setPosition(j * 25, i * 25);
                s_Vector[i].move(28, 31); // offset

                windowManager::getinstance().theWindow->draw(s_Vector[i]);
            }
        }

        if (gameOver)
        {
            font.loadFromFile("Fonts/ARCADECLASSIC.TTF");
            myText.setFont(font);
            myText.setString("GAME OVER");
            myText.setFillColor(sf::Color::Red);
            myText.setPosition(400, 200);



            // Crear y mostrar el botón RETRY
            sf::RectangleShape retryButtonShape(sf::Vector2f(100, 50));
            retryButtonShape.setPosition(400, 300);
            retryButtonShape.setFillColor(sf::Color(255, 255, 255, 255));

            sf::Text retryButtonText;
            retryButtonText.setFont(font);
            retryButtonText.setString("RETRY");
            retryButtonText.setCharacterSize(24);
            retryButtonText.setFillColor(sf::Color::Black);
            retryButtonText.setPosition(420, 310);

            // Dibujar texto y botón
            windowManager::getinstance().theWindow->draw(myText);
            windowManager::getinstance().theWindow->draw(retryButtonShape);
            windowManager::getinstance().theWindow->draw(retryButtonText);

            // Verificar si se ha presionado el botón "RETRY"
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // Reiniciar el juego y eliminar el botón "RETRY"
                resetGame(); // Reiniciar el juego
            }
        }
        else
        {
            for (int i = 0; i < 4; i++) // Normal Draw
            {
                s_Vector[i].setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
                s_Vector[i].setScale(1.7, 1.7);
                s_Vector[i].setPosition(a[i].x * 25, a[i].y * 25);
                s_Vector[i].move(28, 31); // offset
                windowManager::getinstance().theWindow->draw(s_Vector[i]);
            }
        }

        windowManager::getinstance().theWindow->draw(frame);
        windowManager::getinstance().theWindow->display();
    }
}
