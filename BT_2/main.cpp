 #include"Map.h"
Map* Map::instance = NULL;


//do dieu kien thoi gian co han nen em chua kip thiet ke ham main, mong thay thong cam
void main()
{

	Map* map = Map::GetInstance();
	//khoi tao map trong chi co 1 Hero (nguoi choi)
	map->createMap();

	//Khoi tao quai vat ngau nhien
	map->createMonster();

	//Khoi tao cong trinh(neu co), nhap thu cong
	map->createContruction();

	//Khoi tao chien binh, nhap thu cong
	map->createWarrior();

	//khoi dong tro choi
	map->draw();

	//ket thuc
	map->over();

	Map::DeleteInstance();
}