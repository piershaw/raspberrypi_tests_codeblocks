#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_video.h>

///NOTES TO ME AND OTHERS///
/// I got the SDL2 off a drop box but this might work
/// sudo apt-get install cmake libsdl2-dev
/// This is a console application but you could remove the console when the relese is built then the SDL window will only be shown
/// Ill try to include all the lybrary files because setup is always hard
/// use GCC
/// build options->Linker Settings on the right box put this`sdl-config --libs` paths go on the left
/// ../../../usr/lib/libwiringPi.so is in your system in my system its in usr/lib/libwiringPi.so

/*
https://pinout.xyz/pinout/pin40_gpio21
  +-----+-----+---------+------+---+---Pi 3---+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |   2 |   8 |   SDA.1 | ALT0 | 1 |  3 || 4  |   |      | 5v      |     |     |
 |   3 |   9 |   SCL.1 | ALT0 | 1 |  5 || 6  |   |      | 0v      |     |     |
 |   4 |   7 | GPIO. 7 |   IN | 0 |  7 || 8  | 1 | ALT5 | TxD     | 15  | 14  |
 |     |     |      0v |      |   |  9 || 10 | 1 | ALT5 | RxD     | 16  | 15  |
 |  17 |   0 | GPIO. 0 |   IN | 0 | 11 || 12 | 0 | IN   | GPIO. 1 | 1   | 18  |
 |  27 |   2 | GPIO. 2 |   IN | 0 | 13 || 14 |   |      | 0v      |     |     |
 |  22 |   3 | GPIO. 3 |   IN | 0 | 15 || 16 | 0 | IN   | GPIO. 4 | 4   | 23  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | IN   | GPIO. 5 | 5   | 24  |
 |  10 |  12 |    MOSI | ALT0 | 0 | 19 || 20 |   |      | 0v      |     |     |
 |   9 |  13 |    MISO | ALT0 | 0 | 21 || 22 | 0 | IN   | GPIO. 6 | 6   | 25  |
 |  11 |  14 |    SCLK | ALT0 | 0 | 23 || 24 | 1 | OUT  | CE0     | 10  | 8   |
 |     |     |      0v |      |   | 25 || 26 | 1 | OUT  | CE1     | 11  | 7   |
 |   0 |  30 |   SDA.0 |   IN | 1 | 27 || 28 | 1 | IN   | SCL.0   | 31  | 1   |
 |   5 |  21 | GPIO.21 |   IN | 1 | 29 || 30 |   |      | 0v      |     |     |
 |   6 |  22 | GPIO.22 |   IN | 1 | 31 || 32 | 0 | IN   | GPIO.26 | 26  | 12  |
 |  13 |  23 | GPIO.23 |   IN | 0 | 33 || 34 |   |      | 0v      |     |     |
 |  19 |  24 | GPIO.24 |   IN | 0 | 35 || 36 | 0 | IN   | GPIO.27 | 27  | 16  |
 |  26 |  25 | GPIO.25 |   IN | 0 | 37 || 38 | 0 | IN   | GPIO.28 | 28  | 20  |
 |     |     |      0v |      |   | 39 || 40 | 0 | IN   | GPIO.29 | 29  | 21  |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+---Pi 3---+---+------+---------+-----+-----+



*/

#include <wiringPi.h>
#include "Test.h"

int main ( int argc, char** argv )
{

   SDL_Surface* screen = NULL;
   //Start SDL
   SDL_Init( SDL_INIT_VIDEO );

   const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo ();

   int systemX = videoInfo->current_w ;
   int systemY = videoInfo->current_h ;
   Uint8 bpp = videoInfo->vfmt->BitsPerPixel ;

    //Set up screen
    screen = SDL_SetVideoMode( systemX, systemY, bpp, SDL_SWSURFACE );
    if (!screen)
    {
        printf("SDL_SetVideoMode failed\n");
        return 0;
    }

    SDL_Rect r = {0,0,320,240};
    SDL_FillRect(screen,&r, SDL_MapRGB(screen->format, 200,200,0) );


    //Update Screen
    SDL_Flip( screen );

    SDL_Event * event = new SDL_Event();
    //while (event->quit()){

    //}

   //Pause
   SDL_Delay( 20000 );

   //Quit SDL
   SDL_Quit();

     wiringPiSetup();
      pinMode (29, OUTPUT) ;
      for (int i = 0; i < 1000; i++)
      {
        digitalWrite (29, HIGH) ; delay (500) ;
        printf("On");
        digitalWrite (29,  LOW) ; delay (500) ;
        printf("On");
      }

    return 0;
}
