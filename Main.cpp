#include "SFML/Graphics.hpp"
#include<stdio.h>
#include<iostream>
#include<math.h>
#include "Menu.h"
#include<time.h>
#include "SFML/Audio.hpp"
int main()
{

    sf::RenderWindow window( sf::VideoMode( 900, 600 ), "Delivery Drone" );
    window.setFramerateLimit(1200);
    Menu menu(window.getSize().x, window.getSize().y);


    int flag = 0;
    int ra ;
    int ct=0;
    int bcount;
    int bflag=0;
    int br;
    int bc=0;
    int frand = 1;
    int level;
    int kk ;
    int iflag1 = 0;
    int k;
    int randchecker = 0;
    int score = 0;
    int r = 0;

    int color[3]={1, 1, 1};

    int colorflag = 1;
    int men = -1;

    char str[30];
    char scr[30];

    srand(time(NULL));
    int bindex = rand()%10;


    float i;
    float dx = 10;
    float dy = 10;
    float para[5];
    float my=500;
    float mx;
    float msx;
    float msy = 700;
    float bx=1000, by=430;
    float kitspeed;
    float bonarr[10] = {650, 120, 550, 98, 750, 190, 480, 800, 350, 80};

    //text and things

    sf::Font font;
    font.loadFromFile("FontleroyBrownNF.ttf");
    sf::Text tex, scoretex;
    tex.setFont(font);
    tex.setColor(sf::Color::Black);
    tex.setPosition(730, 20);
    scoretex.setFont(font);
    scoretex.setColor(sf::Color::Black);
    scoretex.setPosition(400, 20);
    scoretex.setCharacterSize(40);

    //objects

    sf::Texture tdes;
    sf::Texture thome;
    sf::Texture tice;
    // loading level images

    sf::Texture lev1;
    sf::Texture lev2;
    sf::Texture lev3;

    sf::Texture tdrone;
    sf::Texture ttent1;
    sf::Texture ttent2;
    sf::Texture ttent3;
    sf::Texture medi;
    sf::Texture med;

    lev1.loadFromFile("lv1.jpg");
    lev2.loadFromFile("lv2.jpg");
    lev3.loadFromFile("lv3.jpg");

    sf::Sprite lvl1(lev1);
    sf::Sprite lvl2(lev2);
    sf::Sprite lvl3(lev3);

    sf::Texture menuback;
    menuback.loadFromFile("menuback.jpg");
    sf::Sprite mb(menuback);

    sf::Texture cre;
    cre.loadFromFile("credit.jpg");
    sf::Sprite credits(cre);

    sf::Texture mis;
    mis.loadFromFile("miss.png");
    sf::Sprite missile(mis);

     sf::Texture op;
    op.loadFromFile("nomore.jpg");
    sf::Sprite oops(op);

     sf::Texture exp;
    exp.loadFromFile("ex.png");
    sf::Sprite explosion(exp);

    sf::Texture gameover;
    gameover.loadFromFile("khelashesh.jpg");
    sf::Sprite game(gameover);

      sf::Texture mainmenu;
    mainmenu.loadFromFile("startback.jpg");
    sf::Sprite mainb(mainmenu);

    sf::Texture ins;
    ins.loadFromFile("howtoplay.jpg");
    sf::Sprite instruction(ins);

    med.loadFromFile("pack.png");
    medi.loadFromFile("pack.png");
    tdes.loadFromFile("de.jpg");
    thome.loadFromFile("home.png");
    tice.loadFromFile("snow.jpg");
    tdrone.loadFromFile("dron.png");
    ttent1.loadFromFile("tt.png");
    ttent2.loadFromFile("tt.png");
    ttent3.loadFromFile("tt.png");

    sf::Sprite des(tdes);
    sf::Sprite home(thome);
    sf::Sprite ice(tice);


    sf::Sprite bon(medi);
    bon.setPosition(bx, by);

    sf::Sprite drone(tdrone);
    sf::Sprite tent1(ttent1);
    sf::Sprite tent2(ttent2);
    sf::Sprite tent3(ttent3);
    sf::Sprite kit(medi);
    sf::Sprite mkit(med);

    sf::Texture point;
    point.loadFromFile("point.png");


    sf::Texture point2;
    point2.loadFromFile("point.png");

    sf::Texture point3;
    point3.loadFromFile("point.png");

    sf::SoundBuffer s1;
    s1.loadFromFile("boom.wav");

    sf::Sound expsound;
    expsound.setBuffer(s1);

    sf::SoundBuffer s2;
    s2.loadFromFile("tung.wav");

    sf::Sound received;
    received.setBuffer(s2);

    sf::SoundBuffer s3;
    s3.loadFromFile("no.wav");

    sf::Sound wrong;
    wrong.setBuffer(s3);

    sf::Sprite psprite(point);
    psprite.setColor(sf::Color::Red);
    psprite.setPosition(173, 440);

    sf::Sprite psprite2(point2);
    psprite2.setColor(sf::Color::Red);
    psprite2.setPosition(473, 440);

    sf::Sprite psprite3(point3);
    psprite3.setColor(sf::Color::Red);
    psprite3.setPosition(773, 440);


  // setting missile's initial position

    missile.setPosition(500, 10000);


    // setting position of the camps

    tent1.setPosition(sf::Vector2f(120,400));
    tent2.setPosition(sf::Vector2f(420,400));
    tent3.setPosition(sf::Vector2f(720,400));




    sf::Event event;



    while (window.isOpen())
    {
        if(men == -1) //displaying the game name here
         {

          while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
                {
                    window.clear();
                    window.draw(mainb);
                    window.display();


                }
            men = 0;
         }



        while (window.pollEvent(event))
        {
            if(men==0)
            {

                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        menu.MoveUp();
                        break;

                    case sf::Keyboard::Down:
                        menu.MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menu.GetPressedItem())
                        {
                        case 0:

                            men = 1;
                            para[0] = 0.01;
                            para[1] = 0.03;
                            para[2] = 0.05;
                            para[3] = 0.07;
                            para[4] = 0.09;
                            k = 18;
                            level = 1;
                            kitspeed=0.5;
                            i = 0.6;
                            bcount = 0;
                            ct = 0;
                            drone.setPosition(sf::Vector2f(dx,dy));
                            missile.setPosition(1000,1000);
                            break;
                            case 1:
                              while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                        {
                         window.clear();
                         window.draw(instruction);
                         window.display();
                        }  break;
                        case 2:
                             while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                        {
                         window.clear();
                         window.draw(credits);
                         window.display();


                          }
                            break;
                        case 3:
                            window.close();
                            break;
                        }

                        break;
                    }

                    break;
                case sf::Event::Closed:
                    window.close();

                    break;

                }
            }
        }



        if(level==1)
        {
             if(event.type==sf::Event::Closed)
                    window.close();

             // checking if missile is out of screen
            if(msy<=-100.0)
            {
                msx = float(rand()%800);
                msy = 1200;

                missile.setPosition(msx, msy);
            }
            // taking a random number value to alter the light color of camps

            randchecker++;
            if(randchecker%5000==0)
            {
                colorflag = 1;
            }

            drone.setPosition(sf::Vector2f(dx,dy));
            if(colorflag==1)
            {  //srand(time(NULL));
                r = rand()%3;
                colorflag = 0;
            }
            printf("%d\t", r);
                if(r==0)
                {
                    color[0]=1;
                    color[1]=0;
                    color[2]=0;
                }
                if(r==1)
                {
                    color[0]=0;
                    color[1]=1;
                    color[2]=0;
                }
                if(r==2)
                {
                    color[0]=0;
                    color[1]=0;
                    color[2]=1;
                }


            if(color[0]==1)
            {
                psprite.setColor(sf::Color::Green);
                psprite2.setColor(sf::Color::Red);
                psprite3.setColor(sf::Color::Red);
            }
            if(color[1]==1)
            {
                psprite.setColor(sf::Color::Red);
                psprite2.setColor(sf::Color::Green);
                psprite3.setColor(sf::Color::Red);

            }
            if(color[2]==1)
            {
                psprite.setColor(sf::Color::Red);
                psprite2.setColor(sf::Color::Red);
                psprite3.setColor(sf::Color::Green);

            }

            printf("%d %d %d\n", color[0], color[1], color[2]);
            //setting the drone's position

            drone.setPosition(sf::Vector2f(dx,dy));
            dx += i;

            if(dx>=900.0)
            {
                i=-i;

            }
            else if(dx<=-120.0)
            {
                i = -i;

            }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                i = 0.6;
            }
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                i = -0.6;
            }


            // displaying a kit hanging from the drone
            kit.setPosition(dx+35, dy+35);
           // genearting wind impact
            if(frand == 1)
            {
                srand(time(NULL));
                ra = rand()%5;
                frand = 0;
            }


            // throwing a kit
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && my>=440)
            {
                flag = 1;

                mx = dx+23;
                my = dy+23;
                iflag1 = 1;
                ct++;
                bc=1;
                k--;
                if (i>0.0)
                {
                    kk = 1;
                }
                else kk = -1;


            }
            mkit.setPosition(mx, my);

            // detecting missile collision

                if(drone.getGlobalBounds().intersects(missile.getGlobalBounds()) )
            {

                explosion.setPosition(drone.getPosition());
                expsound.play();
                for(int y=0; y<=800; y++)
                {
                    window.draw(explosion);
                    window.display();
                }

                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                {
                    window.clear();
                    window.draw(game);
                    window.display();


                }
                window.clear();

                my=500;
                msy = 700;

                dx = 10;
                dy = 10;
                flag = 0;
                ct=0;

                bflag=0;

                bc=0;
                frand = 1;

                iflag1 = 0;

                men = 0;
                level = 0;

            }

           // pausing the game
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::R)))
                {
                    window.display();
                }
            }


            // detecting intersection

            if(psprite.getGlobalBounds().intersects(mkit.getGlobalBounds()) )
            {
                if( iflag1 == 1 && color[0]==1 )
                {
                    iflag1 = 0;
                    frand = 1;
                    bcount++;
                    score += 10;
                    k++;
                        received.play();
                 }
                else  if( iflag1 == 1 && color[0]==0 ) {
                        score -= 5;
                        iflag1=0;
                        wrong.play();
                        }

            }

            if(psprite2.getGlobalBounds().intersects(mkit.getGlobalBounds()) )
            {
                 if( iflag1 == 1 && color[1]==1 )
                {
                    iflag1 = 0;
                    frand = 1;
                    bcount++;
                    score += 10;
                    k++;
                       received.play();
                }

                else  if( iflag1 == 1 && color[1]==0 ) {
                        score -= 5;
                        iflag1=0;
                        wrong.play();
                        }
                }

            if(psprite3.getGlobalBounds().intersects(mkit.getGlobalBounds()) )
            {
                 if( iflag1 == 1 && color[2]==1 )
                {
                    iflag1 = 0;
                    frand = 1;
                    bcount++;

                    score += 10;
                    k++;
                       received.play();
                }

                else  if( iflag1 == 1 && color[2]==0 ) {
                        score -= 5;
                        iflag1=0;
                        wrong.play();
                        }

            }




            // appearing bonus item
            if(bcount==3)
            {
                bflag = 1;
                bcount = 0;
            }
            if(bflag==1)
            {
                bx = bonarr[(bindex++)%10];
                bon.setPosition(bx, by);
                bflag=0;
            }
            if(bon.getGlobalBounds().intersects(mkit.getGlobalBounds()))
            {
                if(bc==1)
                {
                    k += 2;
                    bon.setPosition(1000.01, by);
                }
            }

            // loading numbers in string
            sprintf(scr,"Score = %d", score);
            sprintf(str, "Packages Left = %d\n Wind Impact = %d", k, ra);


            scoretex.setString(scr);
            tex.setString(str);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::R)))
                {
                    window.display();
                }
            }


            window.clear( );
            window.draw(home);
            window.draw(scoretex);
            window.draw(tex);


            missile.setPosition(msx, msy);
            msy -= 0.5;

            if(flag==1 && my<=450)
            {
                my += kitspeed;
                mx = mx +  ((para[ra])*kk);
                window.draw(mkit);
                if(my>=450)
                {
                    flag = 0;
                }
            }

            window.draw(drone);
            window.draw(kit);
            window.draw(bon);
            window.draw(tent1);
            window.draw(psprite);
            window.draw(tent2);
            window.draw(psprite2);
            window.draw(tent3);
            window.draw(psprite3);
            window.draw(missile);
            window.display();

            // gameover condition
            if(k==-1 && my >=450)
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                {
                    window.clear();
                    window.draw(game);
                    window.display();
                }


                my=500;
                msy = 700;
                dx = 10;
                dy = 10;
                flag = 0;
                ct=0;
                bflag=0;
                bc=0;
                frand = 1;
                iflag1 = 0;
                men = 0;
                level = 0;
            }

            if(score>=30)
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)))
                {
                    window.clear();
                    window.draw(lvl1);
                    window.display();
                }
                para[0] = 0.01;
                para[1] = 0.04;
                para[2] = 0.07;
                para[3] = 0.10;
                para[4] = 0.13;
                k = 15;
                level = 2;
                kitspeed=0.6;
                i = 0.7;
                bcount=0;
                bflag=0;
                score = 0;
                missile.setPosition(1000,1000);
            }
        }

// level 2


        else if(level==2)
        {  if(event.type==sf::Event::Closed)
                    window.close();

             // checking if missile is out of screen
            if(msy<=-100.0)
            {
                msx = float(rand()%800);
                msy = 1200;

                missile.setPosition(msx, msy);
            }
            // taking a random number value to alter the light color of camps

            randchecker++;
            if(randchecker%5000==0)
            {
                colorflag = 1;
            }

            drone.setPosition(sf::Vector2f(dx,dy));
            if(colorflag==1)
            {  //srand(time(NULL));
                r = rand()%3;
                colorflag = 0;
            }
            printf("%d\t", r);
                if(r==0)
                {
                    color[0]=1;
                    color[1]=0;
                    color[2]=0;
                }
                if(r==1)
                {
                    color[0]=0;
                    color[1]=1;
                    color[2]=0;
                }
                if(r==2)
                {
                    color[0]=0;
                    color[1]=0;
                    color[2]=1;
                }


            if(color[0]==1)
            {
                psprite.setColor(sf::Color::Green);
                psprite2.setColor(sf::Color::Red);
                psprite3.setColor(sf::Color::Red);
            }
            if(color[1]==1)
            {
                psprite.setColor(sf::Color::Red);
                psprite2.setColor(sf::Color::Green);
                psprite3.setColor(sf::Color::Red);

            }
            if(color[2]==1)
            {
                psprite.setColor(sf::Color::Red);
                psprite2.setColor(sf::Color::Red);
                psprite3.setColor(sf::Color::Green);

            }

            printf("%d %d %d\n", color[0], color[1], color[2]);
            //setting the drone's position

            drone.setPosition(sf::Vector2f(dx,dy));
            dx += i;

            if(dx>=900.0)
            {
                i=-i;

            }
            else if(dx<=-120.0)
            {
                i = -i;

            }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                i = 0.7;
            }
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                i = -0.7;
            }


            // displaying a kit hanging from the drone
            kit.setPosition(dx+35, dy+35);
           // genearting wind impact
            if(frand == 1)
            {
                srand(time(NULL));
                ra = rand()%5;
                frand = 0;
            }


            // throwing a kit
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && my>=440)
            {
                flag = 1;

                mx = dx+23;
                my = dy+23;
                iflag1 = 1;
                ct++;
                bc=1;
                k--;
                if (i>0.0)
                {
                    kk = 1;
                }
                else kk = -1;


            }
            mkit.setPosition(mx, my);

            // detecting missile collision

                if(drone.getGlobalBounds().intersects(missile.getGlobalBounds()) )
            {

                explosion.setPosition(drone.getPosition());
                expsound.play();
                for(int y=0; y<=800; y++)
                {
                    window.draw(explosion);
                    window.display();
                }

                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                {
                    window.clear();
                    window.draw(game);
                    window.display();


                }
                window.clear();

                my=500;
                msy = 700;

                dx = 10;
                dy = 10;
                flag = 0;
                ct=0;

                bflag=0;

                bc=0;
                frand = 1;

                iflag1 = 0;

                men = 0;
                level = 0;

            }


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::R)))
                {
                    window.display();
                }
            }


            // detecting intersection

            if(psprite.getGlobalBounds().intersects(mkit.getGlobalBounds()) )
            {
                if( iflag1 == 1 && color[0]==1 )
                {
                    iflag1 = 0;
                    frand = 1;
                    bcount++;
                    score += 10;
                    k++;
                        received.play();
                 }
                else  if( iflag1 == 1 && color[0]==0 ) {
                        score -= 5;
                        iflag1=0;
                        wrong.play();
                        }


            }

            if(psprite2.getGlobalBounds().intersects(mkit.getGlobalBounds()) )
            {
                 if( iflag1 == 1 && color[1]==1 )
                {
                    iflag1 = 0;
                    frand = 1;
                    bcount++;
                    score += 10;
                    k++;
                       received.play();
                }

                else  if( iflag1 == 1 && color[1]==0 ) {
                        score -= 5;
                        iflag1=0;
                        wrong.play();
                        }
                }

            if(psprite3.getGlobalBounds().intersects(mkit.getGlobalBounds()) )
            {
                 if( iflag1 == 1 && color[2]==1 )
                {
                    iflag1 = 0;
                    frand = 1;
                    bcount++;

                    score += 10;
                    k++;
                       received.play();
                }

                else  if( iflag1 == 1 && color[2]==0 ) {
                        score -= 5;
                        iflag1=0;
                        wrong.play();
                        }

            }




            // appearing bonus item
            if(bcount==3)
            {
                bflag = 1;
                bcount = 0;
            }
            if(bflag==1)
            {
                bx = bonarr[(bindex++)%10];
                bon.setPosition(bx, by);
                bflag=0;
            }
            if(bon.getGlobalBounds().intersects(mkit.getGlobalBounds()))
            {
                if(bc==1)
                {
                    k += 2;
                    // bc=0;
                    // bcount=0;
                    bon.setPosition(1000.01, by);
                }
            }


            sprintf(scr,"Score = %d", score);
            sprintf(str, "Packages Left = %d\n Wind Impact = %d", k, ra);


            scoretex.setString(scr);
            tex.setString(str);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::R)))
                {
                    window.display();
                }
            }


            window.clear( );
            window.draw(des);
            window.draw(scoretex);
            window.draw(tex);


            missile.setPosition(msx, msy);
            msy -= 0.7;

            if(flag==1 && my<=450)
            {
                my += kitspeed;
                mx = mx +  ((para[ra])*kk);
                window.draw(mkit);
                if(my>=450)
                {
                    flag = 0;
                }
            }

            window.draw(drone);
            window.draw(kit);
            window.draw(bon);
            window.draw(tent1);
            window.draw(psprite);
            window.draw(tent2);
            window.draw(psprite2);
            window.draw(tent3);
            window.draw(psprite3);
            window.draw(missile);
            window.display();

            if(k==-1 && my >=450)
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                {
                    window.clear();
                    window.draw(game);
                    window.display();
                }


                my=500;
                msy = 700;
                dx = 10;
                dy = 10;
                flag = 0;
                ct=0;
                bflag=0;

                bc=0;
                frand = 1;

                iflag1 = 0;
                men = 0;
                level = 0;
            }

            if(score>=60)
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)))
                {
                    window.clear();
                    window.draw(lvl2);
                    window.display();


                }
                para[0] = 0.01;
                para[1] = 0.05;
                para[2] = 0.10;
                para[3] = 0.15;
                para[4] = 0.20;
                k = 12;
                tex.setColor(sf::Color::White);
                level = 3;
                kitspeed=0.5;
                i = 0.8;
                bcount=0;
                bx = 1000;
                missile.setPosition(1000,1000);
                 score = 0;
            }


        }





// level 3

        else if(level==3)
        { if(event.type==sf::Event::Closed)
                    window.close();

             // checking if missile is out of screen
            if(msy<=-100.0)
            {
                msx = float(rand()%800);
                msy = 1200;

                missile.setPosition(msx, msy);
            }
            // taking a random number value to alter the light color of camps

            randchecker++;
            if(randchecker%5000==0)
            {
                colorflag = 1;
            }

            drone.setPosition(sf::Vector2f(dx,dy));
            if(colorflag==1)
            {  //srand(time(NULL));
                r = rand()%3;
                colorflag = 0;
            }
            printf("%d\t", r);
                if(r==0)
                {
                    color[0]=1;
                    color[1]=0;
                    color[2]=0;
                }
                if(r==1)
                {
                    color[0]=0;
                    color[1]=1;
                    color[2]=0;
                }
                if(r==2)
                {
                    color[0]=0;
                    color[1]=0;
                    color[2]=1;
                }


            if(color[0]==1)
            {
                psprite.setColor(sf::Color::Green);
                psprite2.setColor(sf::Color::Red);
                psprite3.setColor(sf::Color::Red);
            }
            if(color[1]==1)
            {
                psprite.setColor(sf::Color::Red);
                psprite2.setColor(sf::Color::Green);
                psprite3.setColor(sf::Color::Red);

            }
            if(color[2]==1)
            {
                psprite.setColor(sf::Color::Red);
                psprite2.setColor(sf::Color::Red);
                psprite3.setColor(sf::Color::Green);

            }

            printf("%d %d %d\n", color[0], color[1], color[2]);
            //setting the drone's position

            drone.setPosition(sf::Vector2f(dx,dy));
            dx += i;

            if(dx>=900.0)
            {
                i=-i;

            }
            else if(dx<=-120.0)
            {
                i = -i;

            }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                i = 0.8;
            }
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                i = -0.8;
            }


            // displaying a kit hanging from the drone
            kit.setPosition(dx+35, dy+35);
           // genearting wind impact
            if(frand == 1)
            {
                srand(time(NULL));
                ra = rand()%5;
                frand = 0;
            }


            // throwing a kit
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && my>=440)
            {
                flag = 1;

                mx = dx+23;
                my = dy+23;
                iflag1 = 1;
                ct++;
                bc=1;
                k--;
                if (i>0.0)
                {
                    kk = 1;
                }
                else kk = -1;


            }
            mkit.setPosition(mx, my);

            // detecting missile collision

                if(drone.getGlobalBounds().intersects(missile.getGlobalBounds()) )
            {

                explosion.setPosition(drone.getPosition());
                expsound.play();
                for(int y=0; y<=800; y++)
                {
                    window.draw(explosion);
                    window.display();
                }

                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                {
                    window.clear();
                    window.draw(game);
                    window.display();


                }
                window.clear();

                my=500;
                msy = 700;

                dx = 10;
                dy = 10;
                flag = 0;
                ct=0;

                bflag=0;

                bc=0;
                frand = 1;

                iflag1 = 0;

                men = 0;
                level = 0;

            }


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::R)))
                {
                    window.display();
                }
            }


            // detecting intersection

            if(psprite.getGlobalBounds().intersects(mkit.getGlobalBounds()) )
            {
                if( iflag1 == 1 && color[0]==1 )
                {
                    iflag1 = 0;
                    frand = 1;
                    bcount++;
                    score += 10;
                    k++;
                        received.play();
                 }
                else  if( iflag1 == 1 && color[0]==0 ) {
                        score -= 5;
                        iflag1=0;
                        wrong.play();
                        }


            }

            if(psprite2.getGlobalBounds().intersects(mkit.getGlobalBounds()) )
            {
                 if( iflag1 == 1 && color[1]==1 )
                {
                    iflag1 = 0;
                    frand = 1;
                    bcount++;
                    score += 10;
                    k++;
                       received.play();
                }

                else  if( iflag1 == 1 && color[1]==0 ) {
                        score -= 5;
                        iflag1=0;
                        wrong.play();
                        }
                }

            if(psprite3.getGlobalBounds().intersects(mkit.getGlobalBounds()) )
            {
                 if( iflag1 == 1 && color[2]==1 )
                {
                    iflag1 = 0;
                    frand = 1;
                    bcount++;

                    score += 10;
                    k++;
                       received.play();
                }

                else  if( iflag1 == 1 && color[2]==0 ) {
                        score -= 5;
                        iflag1=0;
                        wrong.play();
                        }

            }




            // appearing bonus item
            if(bcount==3)
            {
                bflag = 1;
                bcount = 0;
            }
            if(bflag==1)
            {
                bx = bonarr[(bindex++)%10];
                bon.setPosition(bx, by);
                bflag=0;
            }
            if(bon.getGlobalBounds().intersects(mkit.getGlobalBounds()))
            {
                if(bc==1)
                {
                    k += 2;
                    // bc=0;
                    // bcount=0;
                    bon.setPosition(1000.01, by);
                }
            }


            sprintf(scr,"Score = %d", score);
            sprintf(str, "Packages Left = %d\n Wind Impact = %d", k, ra);


            scoretex.setString(scr);
            tex.setString(str);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::R)))
                {
                    window.display();
                }
            }


            window.clear( );
            window.draw(ice);
            window.draw(scoretex);
            window.draw(tex);


            missile.setPosition(msx, msy);
            msy -= 0.9;

            if(flag==1 && my<=450)
            {
                my += kitspeed;
                mx = mx +  ((para[ra])*kk);
                window.draw(mkit);
                if(my>=450)
                {
                    flag = 0;
                }
            }

            window.draw(drone);
            window.draw(kit);
            window.draw(bon);
            window.draw(tent1);
            window.draw(psprite);
            window.draw(tent2);
            window.draw(psprite2);
            window.draw(tent3);
            window.draw(psprite3);
            window.draw(missile);
            window.display();

            if(k==-1 && my >=450)
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                {
                    window.clear();
                    window.draw(game);
                    window.display();
                }


                my=500;
                msy = 700;
                dx = 10;
                dy = 10;
                flag = 0;
                ct=0;
                bflag=0;

                bc=0;
                frand = 1;

                iflag1 = 0;
                men = 0;
                level = 0;
            }

            if(score>=90)
            {
                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)))
                {
                    window.clear();
                    window.draw(lvl3);
                    window.display();

                    men = 0;
                    level = 0;
                }

                while(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                {
                    window.clear();
                    window.draw(oops);
                    window.display();

                }


                my=500;
                msy = 700;
                dx = 10;
                dy = 10;
                flag = 0;
                ct=0;
                bflag=0;
                bc=0;
                frand = 1;
                score = 0;
                iflag1 = 0;
                men = 0;
                level = 0;
            }
        }



        if(men==0)
        {
            window.clear();
            window.draw(mb);
            menu.draw(window);
            window.display();

        }
    }

 return 0;
}





