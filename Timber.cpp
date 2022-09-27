#include <SFML/Graphics.hpp>

// Make code easier to type with "using namespace"
using namespace sf;

int main()
{
    // Create a video mode object
    VideoMode vm(1920, 1080);

    // Create and open a window for the game
    RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

    // Create a texture to hold a graphic on the GPU
    Texture textureBackground;
    // Load a graphic into the texture
    textureBackground.loadFromFile("graphics/background.png");
    // Create a sprite
    Sprite spriteBackground;
    // Attach the texture to the sprite
    spriteBackground.setTexture(textureBackground);
    // Set the spriteBackground to cover the screen
    spriteBackground.setPosition(0, 0);
    // make a tree sprite
    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810,0);

    //Make a Bee sprite
    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0,800);
    
    //is the bee currently moving?
    bool beeActive = false;
    //how fast can the bee fly
    float beeSpeed = 0.0f;

    //make 3 cloud sprites from 1 texture
    Texture textureCloud;
    //load 1 new texture
    textureCloud.loadFromFile("graphics/cloud.png");
    // 3 new sprites with the same texture
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;

    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    //position of the clounds off screen
    spriteCloud1.setPosition(0,0);
    spriteCloud2.setPosition(0,250);
    spriteCloud3.setPosition(0,500);

    //are the clouds currently on screen
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    //how fast is each cloud?
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    Clock clock;
    while (window.isOpen())
    {
        /*
         ****************************************
         Handle the players input
         ****************************************
         */

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        /*
         ****************************************
         Update the scene
         ****************************************
         */
        Time dt = clock.restart();
        //setup the bee
        if(!beeActive)
        {
            //how fast is the bee
            srand((int)time(0));
            beeSpeed = (rand()%200)+200;

            //how high is the bee
            srand((int)time(0)*10);
            float height = (rand()%500)+500;
            spriteBee.setPosition(2000,height);
            beeActive = true;
        }else
        {
            //move the bee
            spriteBee.setPosition(spriteBee.getPosition().x-(beeSpeed*dt.asSeconds()),spriteBee.getPosition().y);

            if(spriteBee.getPosition().x < -100)
            {
                //set it up ready to be a whole new bee next frame
                beeActive = false;
            }
        }

        //cloud 1
        if(!cloud1Active)
        {
            //how fast is the bee
            srand((int)time(0)*10);
            cloud1Speed = (rand()%200);

            //how high is the bee
            srand((int)time(0)*10);
            float height = (rand()%150);
            spriteCloud1.setPosition(-300,height);
            cloud1Active = true;
        }else
        {
            //move the bee
            spriteCloud1.setPosition(spriteCloud1.getPosition().x+(cloud1Speed*dt.asSeconds()),spriteCloud1.getPosition().y);

            if(spriteCloud1.getPosition().x > 1920)
            {
                //set it up ready to be a whole new bee next frame
                cloud1Active = false;
            }
        }

        //cloud 2
        if(!cloud2Active)
        {
            //how fast is the bee
            srand((int)time(0)*20);
            cloud2Speed = (rand()%200);

            //how high is the bee
            srand((int)time(0)*20);
            float height = (rand()%300) + 150;
            spriteCloud2.setPosition(-300,height);
            cloud2Active = true;
        }else
        {
            //move the bee
            spriteCloud2.setPosition(spriteCloud2.getPosition().x+(cloud2Speed*dt.asSeconds()),spriteCloud2.getPosition().y);

            if(spriteCloud2.getPosition().x > 1920)
            {
                //set it up ready to be a whole new bee next frame
                cloud2Active = false;
            }
        }

        if(!cloud3Active)
        {
            //how fast is the bee
            srand((int)time(0)*30);
            cloud3Speed = (rand()%200);

            //how high is the bee
            srand((int)time(0)*30);
            float height = (rand()%450)-150;
            spriteCloud3.setPosition(-300,height);
            cloud3Active = true;
        }else
        {
            //move the bee
            spriteCloud3.setPosition(spriteCloud3.getPosition().x+(cloud3Speed*dt.asSeconds()),spriteCloud3.getPosition().y);

            if(spriteCloud3.getPosition().x > 1920)
            {
                //set it up ready to be a whole new bee next frame
                cloud3Active = false;
            }
        }

         /*
          ****************************************
          Draw the scene
          ****************************************
          */

          // Clear everything from the last frame
        window.clear();

        // Draw our game scene here
        window.draw(spriteBackground);
        //draw the clouds
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        //draw the tree
        window.draw(spriteTree);
        //draw the insect
        window.draw(spriteBee);
        
        // Show everything we just drew
        window.display();
    }
    return 0;
}


