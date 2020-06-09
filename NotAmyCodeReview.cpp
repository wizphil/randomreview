struct Player
{
	char* name;
	int id;
};

class PlayerManager
{
	Player** pPlayers;
	int numPlayers;
public:
	PlayerManager() : numPlayers(0) {}
	Player* CreatePlayer(const char* name, int id);
	Player* GetPlayerById(int id);
	int GetNumPlayers();
	void DestroyPlayer(Player* pPlayer);
	void DestroyPlayerById(int id);
	void DestroyAllPlayers();
};

Player PlayerManager::CreatePlayer(const char* name, int id)
{
	// Create new Player
	Player* newPlayer = new Player;
	newPlayer.name = name;
	newPlayer.id = id;

	// Add to pPlayers array
	Player** newpPlayers = new Player * [numPlayers+1]
	for (int i = 0; i < numPlayers; ++i)
	{
		newpPlayers[i] = pPlayers[i];
	}
	numPlayers++;
	newpPlayers[numPlayers-1] = newPlayer;
	delete [] pPlayers;
	pPlayers = newpPlayers;
	return newplayer;
}



Player PlayerManager::GetPlayerById(int id)
{
	for (int i = 0; i < numPlayers; ++i)
	{
 		if (pPlayers[i].id == id) 
 		{
 			return pPlayers[i];
 		}
	}
	throw "This player id does not exist!";
}

int PlayerManager::GetNumPlayers()
{
	return numPlayers;
}

void PlayerManager::DestroyPlayer(Player* pPlayer)
{	
	delete pPlayer;
}

void PlayerManager::DestroyPlayerById(int id)
{
	for (int i = 0; i < numPlayers; ++i)
	{
 		if (pPlayers[i].id == id) 
 		{
 			DestroyPlayer(pPlayers[i]);
 		}
	}
	throw "This player id does not exist!";
}

void DestroyAllPlayers()
{
	for (int i = 0; i < numPlayers; ++i)
	{
		DestroyPlayer(pPlayers[i]);
	}
}
