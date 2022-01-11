#include "Bat.h";
#include "Ball.h";
#include <SFML/Graphics.hpp>
#include<cstdlib>
#include<sstream>
#include <iostream>

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong", Style::Fullscreen);
    int score = 0;
    int lives = 3;
    Clock clock;

    //creating a Bat
    Bat bat(1920 / 2, 1080 - 20);

    //create a Ball
    Ball ball(1920 / 2, 0);

    //Creating a HUD
    Text hud;
    Font font;
    font.loadFromFile("fonts/DS-DIGI.ttf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(Color::White);
    hud.setPosition(20, 20);


    while (window.isOpen())
    {
        /*Handle the player input*/
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                //Quit the game
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (bat.GetPosition().left > 0)
            {
                bat.MoveLeft();
            }
            else
            {
                bat.StopLeft();
            }
        }
        else
        {
            bat.StopLeft();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (bat.GetPosition().left + bat.GetPosition().width < window.getSize().x)
            {
                bat.MoveRight();
            }
            else
            {
                bat.StopRight();
            }
        }
        else
        {
            bat.StopRight();
        }

        /*Update the bat, the ball and the HUD*/
        
        //Update the deltatime
        Time deltatime = clock.restart();
        bat.Update(deltatime);
        ball.update(deltatime);

        //Update StringStream
        std::stringstream ss;
        ss << " Score : " << score << " Lives : " << lives;
        hud.setString(ss.str());

        //Handle ball hitting the botom
        if (ball.getPosition().top > window.getSize().y)
        {
            ball.reboundBottom();

            //remove a life
            lives--;
            if (lives <= 0)
            {
                score = 0;
                lives = 3;
            }
        }

        //Handle ball hitting top
        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();
            score++;
            ball.SetSpeed(ball.GetSpeed() * 1.1f);
        }

        //Handle ball hitting sides
        if (ball.getPosition().left<0 || 
            ball.getPosition().left + ball.getPosition().width >window.getSize().x)
        {
            ball.reboundSides();
        }

        //Handle Ball hit the bat
        if (ball.getPosition().intersects(bat.GetPosition()))
        {
            ball.reboundBatOrTop();
        }

        /*Draw the bat, the ball and the HUD*/
        window.clear();
        window.draw(hud);
        window.draw(bat.GetShape());
        window.draw(ball.getShape());
        window.display();

    }
    return 0;
}


