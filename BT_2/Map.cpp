#include"Map.h"
int Over = 0;

Map::~Map()
{
}

void Map::createMap()
{
	cout << "Input size\n";
	cout << "Chieu dai(x): ";
	cin >> X;
	cin.ignore();

	cout << "Chieu rong(y): ";
	cin >> Y;
	cin.ignore();
}

void Map::createContruction()
{
	srand(time(NULL));
	int number_of_contruction;
	//tao so luong cong trinh dua tren dien tich map vd ( map: 3x4 co 1 cong trinh )
	int temp = (Y * X) / 10;
	int x, y;
	if (temp != 0)
	{
		number_of_contruction = rand() % temp + 1;//ngau nhien tu 1
	}
	else
		number_of_contruction = 0;// khong co cong trinh

	for (int i = 0; i < number_of_contruction; i++)//tao cong trinh
	{
		drawMap();//ve Map de nguoi choi de nhap

		cout << "Nhap toa do cong trinh (khong nhap trung voi quai)" << "(x be hon " << Y - 1 << " va y be hon " << X - 1 << ")\n";//do khong du dieu kien thoi gian nen em chua the viet ham kiem tra trung va cho tat ca ngau nhien
		cout << "x: ";
		cin >> x;
		cin.ignore();
		cout << "y: ";
		cin >> y;
		cin.ignore();

		Construction* temp = new Construction(x, y);
		temp->input();
		construction_list.push_back(temp);
	}
	cout << "Da tao xong cong trinh\n";
}

void Map::createMonster()
{
	srand(time(NULL));
	int number_of_monster;
	//tao so luong quai dua tren dien tich map 
	int temp = (Y * X) / 4;
	int x, y;
	if (temp != 0)
	{
		number_of_monster = rand() % temp + 1;//ngau nhien tu 1
	}
	else
		number_of_monster = 1;//map qua nho(<4) cho ngau nhien 1 quai

	for (int i = 0; i < number_of_monster; i++)//tao quai
	{
		drawMap();
		do
		{
			x = rand() % (X - 1) + 1;
			y = rand() % (Y - 1) + 1;
		} while (x == 0 && y == 0);

		Monster* monster = new Monster(x, y);
		monster->input();
		monster_list.push_back(monster);
	}
	cout << "Da tao xong quai vat";
}

void Map::createWarrior()
{
	srand(time(NULL));
	int number_of_warrior;
	//tao so luong chien binh bang so luong quai
	int temp = (Y * X) / 4;
	int x, y;
	if (temp != 0)
	{
		number_of_warrior = rand() % temp + 1;//ngau nhien tu 1
	}
	else
		number_of_warrior = 1;//do map nho nen duoc tao 1 chien binh

	for (int i = 0; i < number_of_warrior; i++)//tao chien binh
	{
		drawMap();
		cout << "Nhap toa do chien binh (khong nhap trung voi quai)"<<"(x be hon "<<Y-1<<" va y be hon "<<X-1<<")\n";//do khong du dieu kien thoi gian nen em chua the viet ham kiem tra trung va cho tat ca ngau nhien
		cout << "x: ";
		cin >> x;
		cin.ignore();
		cout << "y: ";
		cin >> y;
		cin.ignore();

		Warrior* warrior = new Warrior(x, y);
		warrior->input();
		warrior_list.push_back(warrior);
	}
	cout << "Da tao xong chien binh\n";
}

void Map::draw()
{
	int cnt(0);

	vector<Warrior*> infantry;

	do
	{
		system("cls");
		cout << "Bieu tuong\n";
		cout << "Hero: 1\n";
		cout << "Chien binh: 2\n";
		cout << "Quai vat: 3\n";
		cout << "Cong trinh: 4\n";
		cout << "W,A,S,D de di chuyen\n";
		//tao moi ban do
		int** map = new int* [Y];
		for (int i = 0; i < Y; i++)
			map[i] = new int[X];

		for (int i = 0; i < Y; i++)
			for (int j = 0; j < X; j++)
			{
				map[i][j] = 0;
			}

		//lay vi tri cac vat the
		for (int i = 0; i < warrior_list.size(); i++)
			map[warrior_list[i]->getY()][warrior_list[i]->getX()] = 2;

		for (int i = 0; i < monster_list.size(); i++)
			map[monster_list[i]->getY()][monster_list[i]->getX()] = 3;

		for (int i = 0; i < construction_list.size(); i++)
			map[construction_list[i]->getY()][construction_list[i]->getX()] = 4;

		map[hero.getY()][hero.getX()] = 1;


		//Ve tro choi
		for (int i = 0; i < Y; i++)
		{
			for (int j = 0; j < X; j++)
			{
				cout << map[i][j]<<" ";
			}
			cout << endl<<endl;
		}
		move();
		//thu nhan linh
		if (map[hero.getY()][hero.getX()] == 2)
		{
			for (int i = 0; i < warrior_list.size(); i++)
			{
				if (warrior_list[i]->getY() == hero.getY() && warrior_list[i]->getX() == hero.getX())//tim chien binh tai vi tri Hero di den
				{
					infantry.push_back(warrior_list[i]);
					warrior_list.erase(warrior_list.begin() + i);
					break;
				}
			}
		}
		//chien dau voi quai vat
		else if (map[hero.getY()][hero.getX()] == 3)
		{
			for (int i = 0; i < monster_list.size(); i++)
			{
				if (monster_list[i]->getX() == hero.getX() && monster_list[i]->getY() == hero.getY())//tim quai vat tai vi tri Hero di den
				{
					battle(infantry, monster_list[i]);
					if (Over == -1)break;//cac chien binh da hi sinh, khong xoa quai vat
					delete monster_list[i];
					monster_list.erase(monster_list.begin() + i);
					break;
				}
			}
		}
		//nang cap linh
		else if (map[hero.getY()][hero.getX()] == 4)
		{
			for (int i = 0; i < construction_list.size(); i++)
			{
				if (construction_list[i]->getX() == hero.getX() && construction_list[i]->getY() == hero.getY())//tim cong trinh tai vi tri Hero di den
				{
					cout << "Chuc mung ban da di chuyen den Cong Trinh " << construction_list[i]->getName()<<endl;
					cout << "Linh ban da duoc tang cap\n";
					Sleep(2000);
					for (int j = 0; j < infantry.size(); j++)
					{
						infantry[j]->levelUp();
					}
					//xoa cong trinh
					delete construction_list[i];
					construction_list.erase(construction_list.begin() + i);
				}
			}
		}

		//xoa map
		for (int i = 0; i < Y; i++)
			delete[]map[i];
		delete[]map;

		//di chuyen 3 luot thi linh cua ban than va tat ca quai vat se duoc tang 1 cap
		cnt++;
		if (cnt % 3 == 0 && Over == 0)
		{
			cout << "Da qua 1 thoi gian dai, linh cua ban va quai vat da tang them 1 cap\n";
			Sleep(2000);
			for (int j = 0; j < infantry.size(); j++)
			{
				infantry[j]->levelUp();
			}
			for (int i = 0; i < monster_list.size(); i++)
			{
				monster_list[i]->levelUp();
			}
			cnt = 0;
		}
		//dieu kien thang
		if (monster_list.size() == 0)
			Over = 1;
	} while (Over == 0);
	//xoa du lieu con xot lai
	for (int i = 0; i < infantry.size(); i++)
	{
		delete infantry[i];
	}
	infantry.clear();
	for (int i = 0; i < construction_list.size(); i++)
	{
		delete construction_list[i];
	}
	construction_list.clear();
	for (int i = 0; i < monster_list.size(); i++)
	{
		delete monster_list[i];
	}
	monster_list.clear();
	for (int i = 0; i < warrior_list.size(); i++)
	{
		delete warrior_list[i];
	}
	warrior_list.clear();
	//ket thuc

}

void Map::move()
{
	string c;
	do
	{
		cout << "Di chuyen cua ban: ";
		getline(cin, c);
	} while (c != "w" && c != "W" && c != "a" && c != "A" && c != "s" && c != "S" && c != "d" && c != "D");
	if (c == "w" || c == "W")
		hero.moveUp();
	else if (c == "a" || c == "A")
		hero.moveLeft();
	else if (c == "s" || c == "S")
		hero.moveDown();
	else if (c == "d" || c == "D")
		hero.moveRight();
}

void Map::over()
{
	system("cls");
	if (Over == -1)
	{
		cout << "Ban da thua\n";
	}
	else if (Over == 1)
		cout << "Ban da chien thang\n";

	else cout << "Chuong trinh loi \n";
}

void Map::battle(vector<Warrior*> &infantry, Monster* monster)
{
	int temp;

	if (infantry.size() == 0)
	{
		Over = -1;
		return ;
	}
	else
	{
		while (infantry.size() != 0)//danh den khi khong con chien binh nao song
		{
			temp = monster->getHP() - infantry[0]->getATK();// nguoi danh truoc
			cout << "Chien binh(" << infantry[0]->getName() << ") da gay ra " << infantry[0]->getATK() << " len quai vat(" << monster->getName()<<")\n";
			monster->setHP(temp);
			cout << "Quai vat con " << monster->getHP() << " HP\n";
			if (monster->getHP() <= 0)//quai vat chet, chien dau thanh cong
			{
				cout << "Quai vat da bi tieu diet, tiep tuc cuoc hanh trinh nao\n";
				Over = 0;
				system("pause");
				return ;
			}
			temp = infantry[0]->takeDamage() - monster->Attack();//mau va giap cua chien binh tru cho don danh cua quai vat
			cout << "Quai vat(" << monster->getName() << ") da gay ra " << monster->Attack() << " len chien binh(" << infantry[0]->getName() << ")\n";
			
			if (temp < infantry[0]->getHP())
			{
				infantry[0]->setHP(temp);
			}
			cout << "Chien binh con " << infantry[0]->getHP() << " HP\n";
			if (infantry[0]->getHP() <= 0)
			{
				cout << "Chien binh hi sinh\n";
				delete infantry[0];
				infantry.erase(infantry.begin() + 0);
				Over = -1;
				system("pause");
				return;
			}
			cout << "Het 1 luot\n";
			//den chien binh tiep theo neu 1 chien binh chet
			Sleep(2000);//dung 3s
		}
		Over = -1;
		return ;
	}
}
void Map::drawMap()
{

	system("cls");
	cout << "Bieu tuong\n";
	cout << "Hero: 1\n";
	cout << "Chien binh: 2\n";
	cout << "Quai vat: 3\n";
	cout << "Cong trinh: 4\n";
	//tao moi ban do
	int** map = new int* [Y];
	for (int i = 0; i < Y; i++)
		map[i] = new int[X];

	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++)
		{
			map[i][j] = 0;
		}
	//lay vi tri cac vat the
	for (int i = 0; i < warrior_list.size(); i++)
		map[warrior_list[i]->getY()][warrior_list[i]->getX()] = 2;

	for (int i = 0; i < monster_list.size(); i++)
		map[monster_list[i]->getY()][monster_list[i]->getX()] = 3;

	for (int i = 0; i < construction_list.size(); i++)
		map[construction_list[i]->getY()][construction_list[i]->getX()] = 4;

	map[hero.getY()][hero.getX()] = 1;


	//Ve tro choi
	cout << endl;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cout << map[i][j]<<" ";
		}
		cout << endl << endl;
	}

	for (int i = 0; i < Y; i++)
		delete[]map[i];
	delete[]map;
}