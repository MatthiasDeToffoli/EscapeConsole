#include "GameManager.h"
#include <iostream>
#include <string.h>


using namespace std;

namespace Fr
{
	namespace MatthiasDeToffoli
	{
		namespace EscapeConsole
		{
			/// <summary>
			/// Default constructor
			/// </summary>
			GameManager::GameManager()
			{
				mPlayerText = new char();
			}

			/// <summary>
			/// Do all the game action and interaction
			/// </summary>
			/// <returns><c>true</c> if the game continue, <c>false<c> if the player want to quit the game</returns>
			bool GameManager::GameLoop() 
			{
				std::cout << "For help type help in the console any time\n\n";
				
				std::cin >> mPlayerText;
				
				std::cout << "\n";

				//use low chars
				for (int i = 0, l = (int)std::strlen(mPlayerText); i < l; i++)
				{
					mPlayerText[i] = std::tolower(mPlayerText[i]);
				}
				
				if (strcmp(mPlayerText, NEW) == 0)
				{
					//Restart game
				}
				else if (strcmp(mPlayerText, SAVE) == 0)
				{
					//Save game
				}
				else if (strcmp(mPlayerText, LOAD) == 0)
				{
					//Load game
				}
				else if (strcmp(mPlayerText, HELP) == 0)
				{
					std::cout << HELP_CONTENT;
				}
				else if (strcmp(mPlayerText, QUIT) == 0)
				{
					return false;
				}

				return true;
			}

			/// <summary>
			/// Default destructor
			/// </summary>
			GameManager::~GameManager()
			{
				
			}
		}
	}
}

