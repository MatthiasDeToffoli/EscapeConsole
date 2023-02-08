#pragma once
#include <map>
#include "Direction.cpp"

using namespace std;
using Fr::MatthiasDeToffoli::EscapeConsole::Utils::Direction;

namespace Fr
{
	namespace MatthiasDeToffoli
	{
		namespace EscapeConsole
		{
			class Level
			{
				private:
					/// <summary>
					/// x exit
					/// </summary>
					const int mExitX = 0;

					/// <summary>
					/// y exit
					/// </summary>
					const int mExitY = 9;

					/// <summary>
					/// position x of the player
					/// </summary>
					int mPlayerPosX;

					/// <summary>
					/// position y of the player
					/// </summary>
					int mPlayerPosY;

					/// <summary>
					/// Map of the game, player can move on true squares and can't on false squares.
					/// </summary>
					/// <remarks>
					/// 
					///					          LEFT y - n         y         RIGHT y + n
					///					|---------------------------------------------------------- 
					///	  TOP x - n		|
					///					|
					///		   x		|
					///	 BOTTOM x + n	|
					///					|
					/// 
					/// </remarks>
					const bool mMap[10][10] = {
						{false,false,true ,true ,true ,false,false,false,true ,true },
						{false,false,false,true ,false,true ,true ,true ,true ,false},
						{false,true ,true ,true ,true ,false,true ,true ,false,false},
						{false,true ,false,true ,false,true ,false,true ,false,true },
						{true ,true ,false,true ,false,true ,true ,true ,false,true },
						{false,false,true ,true ,true ,false,true ,false,false,true },
						{false,false,true ,false,false,true ,true ,true ,false,true },
						{false,true ,true ,false,true ,true ,true ,false,false,true },
						{false,true ,false,true ,true ,false,true ,false,false,true },
						{false,true ,true ,true ,false,true ,true ,true ,true ,true },
					};

					/// <summary>
					/// Check if we can move on a direction
					/// </summary>
					/// <param name="x">x map case</param>
					/// <param name="y">y map case</param>
					/// <returns><c>true</c> if we can move on the direction, <c>false</c> instead</returns>
					bool CanMove(int x, int y);

				public:
					/// <summary>
					/// x start position
					/// </summary>
					const int startX = 4;

					/// <summary>
					/// y start position
					/// </summary>
					const int startY = 0;

					/// <summary>
					/// Default constructor
					/// </summary>
					Level();

					/// <summary>
					/// Check if we can move on a direction
					/// </summary>
					/// <param name="pDir">Direction we want to check</param>
					/// <returns><c>true</c> if we can move on the direction, <c>false</c> instead</returns>
					bool CanMove(Direction pDir);

					/// <summary>
					/// Move to a direction
					/// </summary>
					/// <param name="pDir"></param>
					bool Move(Direction pDir);

					/// <summary>
					/// If the player is on exit or not
					/// </summary>
					/// <returns></returns>
					bool IsOnExit();

					/// <summary>
					/// Default Destructor
					/// </summary>
					~Level();
			};

			
		}
	}
}

