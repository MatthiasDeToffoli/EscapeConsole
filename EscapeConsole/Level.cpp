#include "Level.h"

namespace Fr
{
	namespace MatthiasDeToffoli
	{
		namespace EscapeConsole
		{
			/// <summary>
			/// Default constructor
			/// </summary>
			Level::Level()
			{
				playerPosX = startX;
				playerPosY = startY;
			}

			/// <summary>
			/// Check if we can move on a direction
			/// </summary>
			/// <param name="x">x map case</param>
			/// <param name="y">y map case</param>
			/// <returns><c>true</c> if we can move on the direction, <c>false</c> instead</returns>
			bool Level::CanMove(int x, int y)
			{
				//Do it for check but remove it after
				int lMaxX = sizeof(mMap) / sizeof(*mMap);
				int lMaxY = sizeof(mMap[x]) / sizeof(*mMap[x]);
				if (x >= 0 && x < lMaxX)
				{
					if (y >= 0 && y < lMaxY) 
					{
						return mMap[x][y];
					}
				}
				return false;
			}

			/// <summary>
			/// Check if we can move on a direction
			/// </summary>
			/// <param name="pDir">Direction we want to check</param>
			/// <returns><c>true</c> if we can move on the direction, <c>false</c> instead</returns>
			bool Level::CanMove(Direction pDir) 
			{
				switch (pDir)
				{
					case Direction::LEFT:
						return CanMove(playerPosX, playerPosY - 1.);
					case Direction::RIGHT:
						return CanMove(playerPosX, playerPosY + 1);
					case Direction::BOTTOM:
						return CanMove(playerPosX + 1, playerPosY);
					case Direction::TOP:
						return CanMove(playerPosX - 1, playerPosY);
				}

				return false;
			}

			/// <summary>
			/// Move to a direction
			/// </summary>
			/// <param name="pDir"></param>
			bool Level::Move(Direction pDir)
			{
				if (CanMove(pDir)) 
				{
					switch (pDir)
					{
					case Direction::LEFT:
						playerPosY--;
						break;
					case Direction::RIGHT:
						playerPosY++;
						break;
					case Direction::BOTTOM:
						playerPosX++;
						break;
					case Direction::TOP:
						playerPosX--;
						break;
					}
					return true;
				}
				return false;

			}

			/// <summary>
			/// Default Destructor
			/// </summary>
			Level::~Level()
			{

			}
		}
	}
}