#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "GameState.cpp"

using Fr::MatthiasDeToffoli::EscapeConsole::Enums::GameState;

namespace Fr 
{
	namespace MatthiasDeToffoli
	{
		namespace EscapeConsole 
		{
			/// <summary>
			/// Class manage key word
			/// </summary>
			class GameManager
			{
				private:
					/// <summary>
					/// Constant for test if the user need to see the help
					/// </summary>
					const char *NEW = "new";

					/// <summary>
					/// Constant for test if the user need to see the help
					/// </summary>
					const char *SAVE = "save";

					/// <summary>
					/// Constant for test if the user need to see the help
					/// </summary>
					const char *LOAD = "load";

					/// <summary>
					/// Constant for test if the user need to see the help
					/// </summary>
					const char *HELP = "help";

					/// <summary>
					/// Constant for test if the user want to quit the app
					/// </summary>
					const char *QUIT = "quit";

					/// <summary>
					/// Content describe all key words possible in the app
					/// </summary>
					const char *HELP_CONTENT = "-> Help open the help screen\n-> Left chose left path if possible\n-> Right chose the right path if possible\n-> Forward chose to go forward if it's possible\n-> Back chose to go back if it's possible\n-> Left chose left path if possible\n-> New create a new game\n-> Save save your current game\n-> Load load your previous game\n-> Quit close the consol\n\n";

					/// <summary>
					/// Text of the player
					/// </summary>
					char *mPlayerText;

				public:
					/// <summary>
					/// Default constructor
					/// </summary>
					GameManager();

					/// <summary>
					/// Do all the game action and interaction
					/// </summary>
					/// <returns><c>true</c> if the game continue, <c>false<c> if the player want to quit the game</returns>
					bool GameLoop();

					/// <summary>
					/// Default destructor
					/// </summary>
					~GameManager();
			};
		}
	}
}


