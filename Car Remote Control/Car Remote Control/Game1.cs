using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using System.Net;
using System;

namespace Car_Remote_Control
{
    /// <summary>
    /// This is the main type for your game.
    /// </summary>
    public class Game1: Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here

            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);

            // TODO: use this.Content to load your game content here
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// game-specific content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            if(GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed || Keyboard.GetState().IsKeyDown(Keys.Escape))
                Exit();

            // TODO: Add your update logic here
            string state;
            if(Keyboard.GetState().IsKeyDown(Keys.Left) && Keyboard.GetState().IsKeyDown(Keys.Up))
                state ="leftforward";
            else if(Keyboard.GetState().IsKeyDown(Keys.Right) && Keyboard.GetState().IsKeyDown(Keys.Up))
                state ="rightforward";
            else if(Keyboard.GetState().IsKeyDown(Keys.Left) && Keyboard.GetState().IsKeyDown(Keys.Down))
                state ="leftbackward";
            else if(Keyboard.GetState().IsKeyDown(Keys.Right) && Keyboard.GetState().IsKeyDown(Keys.Down))
                state ="rightbackward";
            else if(Keyboard.GetState().IsKeyDown(Keys.Left))
                state ="left";
            else if(Keyboard.GetState().IsKeyDown(Keys.Right))
                state ="right";
            else if(Keyboard.GetState().IsKeyDown(Keys.Up))
                state ="forward";
            else if(Keyboard.GetState().IsKeyDown(Keys.Down))
                state ="backward";
            //else if(Keyboard.GetState().IsKeyDown(Keys.Enter))
            //    state ="moving";
            //else if(Keyboard.GetState().IsKeyDown(Keys.Space))
            //    state ="Dead Man's Switch";
            else
                state ="idle";

            if(state != "idle" && IsActive)
            {
                try
                {
                    string html = string.Empty;
                    string url = @"http://10.40.190.113:8080/setstate/"+state;

                    System.Net.HttpWebRequest request = (System.Net.HttpWebRequest)System.Net.WebRequest.Create(url);
                    request.AutomaticDecompression = System.Net.DecompressionMethods.GZip;

                    //System.Console.WriteLine("BEFORE usiing");
                    using(System.Net.HttpWebResponse response = (System.Net.HttpWebResponse)request.GetResponse())
                    {
                        //response
                        //System.Console.WriteLine(response);
                    }
                }
                catch(Exception e)
                {
                    System.Console.WriteLine("error");
                }
            }


            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.CornflowerBlue);

            // TODO: Add your drawing code here

            base.Draw(gameTime);
        }
    }
}
