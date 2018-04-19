#include "CutiaSDL.hpp"
#include "State.hpp"
#include "Game.hpp"


int texture_width = 100;
int texture_height = 100;

SDL_Texture* texture = NULL;

SDL_Renderer* screen = NULL;


State::State()
{
    quitRequested = false;    

    SDL_Surface * image = NULL;
    image = IMG_Load("../sample_assets/donut.png");

    if (image == NULL)
    {
		printf("Image failed loading.\n");
        std::exit(EXIT_FAILURE);
    }

	screen = Game::GetInstance().GetRenderer();

	texture = SDL_CreateTextureFromSurface(screen, image);

    if (texture == NULL)
    {
		printf("Texture failed loading.\n");
        std::exit(EXIT_FAILURE);
    }

    texture_width = image->w;
    texture_height = image->h;

    SDL_FreeSurface(image);
    image = NULL;

}

State::~State(){ }


void State::Update(float dt)
{
    
}

void State::Render()
{

	SDL_Rect renderQuad = {112, 122, texture_width, texture_height};
	SDL_RenderCopy(screen, texture, NULL, &renderQuad);
    
}

bool State::QuitRequested()
{
    return quitRequested;
}


void State::Input()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) 
    {
		if(event.type == SDL_QUIT) 
        {
			quitRequested = true;
		}
	}
}