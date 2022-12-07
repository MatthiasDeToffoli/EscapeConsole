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
			/// Constant for test if the user need to see the help
			/// </summary>
			const char* GameManager::HELP = "help";

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
				if(!mAI.waitingAnswer)
					std::cout << mAI.GetNextDialog();
				
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

				if (mAI.waitingAnswer)
				{
					mAI.TestPlayerAnswer(mPlayerText);
				}

				return true;
			}

			/// <summary>
			/// Default destructor
			/// </summary>
			GameManager::~GameManager()
			{
				delete &mAI;
				delete mPlayerText;
			}
		}
	}
}

