#include <iostream>
#include <vector>
#include <map>
using namespace std;

// RPG Extreme

// @ : player
// & : monster
// M : boss
// B : box
// ^ : spike
// # : wall
// . : empty

struct point
{
    int x;
    int y;
    point() {}
    point(int nx, int ny)
    {
        x = nx;
        y = ny;
    }
    bool operator<(const point &e) const
    {
        if (e.x == x)
            return y > e.y;
        return x > e.x;
    }
};

struct weapon
{
    int att;
    weapon() {}
    weapon(int a) { att = a; }
};

struct armor
{
    int def;
    armor() {}
    armor(int a) { def = a; }
};

/*
HP Regeneration(HR) : 전투에서 승리할 때마다 체력을 3 회복한다. 체력은 최대 체력 수치까지만 회복된다.
Reincarnation(RE) : 주인공이 사망했을 때 소멸하며, 주인공을 최대 체력으로 부활시켜 준 뒤, 주인공을 첫 시작 위치로 돌려보낸다. 레벨이나 장비 등의 다른 정보는 변함이 없다. 전투 중이던 몬스터가 있다면 해당 몬스터의 체력도 최대치로 회복된다. 소멸한 뒤에 다시 이 장신구를 얻는다면 또 착용한다.
Courage(CO) : 모든 전투에서, 첫 번째 공격에서 주인공의 공격력(무기 합산)이 두 배로 적용된다. 즉, 모든 첫 공격에서 몬스터에게 max(1, 공격력×2 – 몬스터의 방어력)만큼의 데미지를 입힌다.
Experience(EX) : 얻는 경험치가 1.2배가 된다. 소수점 아래는 버린다.
Dexterity(DX) : 가시 함정에 입는 데미지가 1로 고정되며, Courage 장신구와 함께 착용할 경우, Courage의 공격력 효과가 두 배로 적용되는 대신 세 배로 적용된다.
Hunter(HU) : 보스 몬스터와 전투에 돌입하는 순간 체력을 최대치까지 회복하고, 보스 몬스터의 첫 공격에 0의 데미지를 입는다.
Cursed(CU) : 아무 능력이 없으며, 그냥 장신구 한 자리를 차지한다.
*/
struct ornament
{
    string type;
    ornament() {}
    ornament(string s)
    {
        type = s;
    }
};

// TYPE_WEAPON = 'W';
// TYPE_ARMOR = 'A';
// TYPE_ORNAMENT = 'O';
struct box
{
    char type;
    weapon weapon_;
    armor armor_;
    ornament ornament_;
    box() {}
    box(weapon w)
    {
        weapon_ = w;
        type = 'W';
    }
    box(armor a)
    {
        armor_ = a;
        type = 'A';
    }
    box(ornament o)
    {
        ornament_ = o;
        type = 'O';
    }
};

struct player
{
    int lv, hp, maxhp, att, def;
    int xp; // max = 5*lv
    point pos;
    weapon wp;
    armor amr;
    vector<ornament> ornaments;
    bool hasweapon, hasarmor;
    player() {}
    player(int px, int py)
    {
        lv = 1;
        hp = maxhp = 20;
        att = 2;
        def = 2;
        pos.x = px;
        pos.y = py;
        hasweapon = hasarmor = false;
    }
};

struct monster
{
    string name;
    int att, def, hp, maxhp, xp;
    monster() {}
    monster(string n, int a, int d, int h, int x)
    {
        name = n;
        att = a;
        def = d;
        hp = h;
        maxhp = h;
        xp = x;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // input

    int n, m; // n:세로, m:가로
    cin >> n >> m;
    int plgenx, plgeny; // player pos (used on generate)
    vector<string> level;
    vector<char> firstRow;
    for (int i = 0; i <= m; i++)
        firstRow.push_back('#');
    string firstRowStr(firstRow.begin(), firstRow.end());
    level.push_back(firstRowStr);
    int k = 0; // 몬스터의 수
    int l = 0; // 박스의 수
    for (int i = 1; i <= n; i++)
    {
        string mapgen_s1;
        cin >> mapgen_s1;
        level.push_back('#' + mapgen_s1);
        int horzpos = 1;
        for (char mapgen_c : mapgen_s1)
        {
            if (mapgen_c == '@')
            {
                plgenx = horzpos;
                plgeny = i;
                level[plgeny][plgenx] = '.';
            }
            horzpos++;
            if (mapgen_c == '&' || mapgen_c == 'M')
            {
                k++;
            }
            if (mapgen_c == 'B')
                l++;
        }
    }
    string input; // player moves
    cin >> input;
    player player(plgenx, plgeny); // player.
    map<point, monster> monsters;
    map<point, box> boxes;
    for (int i = 0; i < k; i++)
    {
        int r, c, w, a, h, e;
        string s;
        cin >> r >> c >> s >> w >> a >> h >> e;
        monster genmonster(s, w, a, h, e);
        point genmp(c, r);
        monsters.insert({genmp, genmonster});
    }

    for (int i = 0; i < l; i++)
    {
        int r, c;
        char t;
        cin >> r >> c >> t;
        point genorn(c, r);
        switch (t)
        {
        case 'W':
        {
            int s1;
            cin >> s1;
            weapon genw(s1);
            box genbw(genw);
            boxes.insert({genorn, genbw});
            break;
        }
        case 'A':
        {
            int s2;
            cin >> s2;
            armor gena(s2);
            box genba(gena);
            boxes.insert({genorn, genba});
            break;
        }
        case 'O':
        {
            string s3;
            cin >> s3;
            ornament geno(s3);
            box genbo(geno);
            boxes.insert({genorn, genbo});
            break;
        }
        }
    }

    // simulation
    int turns = 0; // 턴 수
    bool dead = false;
    bool win = false;
    monster mon;

    for (char c : input)
    {
        turns++;
        point originalPos = player.pos;

        // calculate player ornaments
        int hrcount = 0, recount = 0, cocount = 0, excount = 0, dxcount = 0, hucount = 0, cucount = 0;
        for (auto o : player.ornaments)
        {
            if (o.type.compare("HR") == 0)
                hrcount++;
            if (o.type.compare("RE") == 0)
                recount++;
            if (o.type.compare("CO") == 0)
                cocount++;
            if (o.type.compare("EX") == 0)
                excount++;
            if (o.type.compare("DX") == 0)
                dxcount++;
            if (o.type.compare("HU") == 0)
                hucount++;
            if (o.type.compare("CU") == 0)
                cucount++;
        }
        map<string, bool> ornas;
        ornas.insert({"HR", hrcount});
        ornas.insert({"RE", recount});
        ornas.insert({"CO", cocount});
        ornas.insert({"EX", excount});
        ornas.insert({"DX", dxcount});
        ornas.insert({"HU", hucount});
        ornas.insert({"CU", cucount});

        switch (c)
        {
        case 'L':
            player.pos.x--;
            break;
        case 'R':
            player.pos.x++;
            break;
        case 'U':
            player.pos.y--;
            break;
        case 'D':
            player.pos.y++;
            break;
        }

        if (player.pos.y > n || player.pos.x > m)
        {
            player.pos = originalPos;
        }
        else if (level[player.pos.y][player.pos.x] == '#')
        {
            player.pos = originalPos;
        }
        if (level[player.pos.y][player.pos.x] == '^')
        {
            if (ornas["DX"])
                player.hp -= 1;
            else
                player.hp -= 5;
            if (player.hp <= 0)
                goto death;
        }
        else if (level[player.pos.y][player.pos.x] == 'B')
        {
            box curbox = boxes[player.pos];
            if (curbox.type == 'W')
            {
                player.wp = curbox.weapon_;
                player.hasweapon = true;
            }
            else if (curbox.type == 'A')
            {
                player.amr = curbox.armor_;
                player.hasarmor = true;
            }
            else
            { // ornament
                if (player.ornaments.size() < 4 && !ornas[curbox.ornament_.type])
                {
                    player.ornaments.push_back(curbox.ornament_);
                }
            }
            level[player.pos.y][player.pos.x] = '.';
        }
        else if (level[player.pos.y][player.pos.x] == '&')
        {
            mon = monsters[player.pos];
            bool firstTurn = true;
            while (player.hp > 0 && mon.hp > 0)
            {
                // player attack
                int boost = 1;
                if (firstTurn && ornas["CO"])
                {
                    if (ornas["DX"])
                        boost = 3;
                    else
                        boost = 2;
                }
                int playeratt = player.att;
                if (player.hasweapon)
                    playeratt += player.wp.att;
                int playerdef = player.def;
                if (player.hasarmor)
                    playerdef += player.amr.def;
                mon.hp -= max(1, (playeratt)*boost - mon.def);
                if (mon.hp <= 0)
                    break;
                player.hp -= max(1, mon.att - playerdef);
                firstTurn = false;
            }
            if (player.hp <= 0)
                goto death;
            level[player.pos.y][player.pos.x] = '.';
            if (ornas["HR"])
                player.hp = min(player.maxhp, player.hp + 3);
            float boost = 1;
            if (ornas["EX"])
                boost = 1.2f;
            player.xp += mon.xp * boost;
            if (player.xp >= 5 * player.lv)
            {
                player.lv++;
                player.xp = 0;
                player.maxhp += 5;
                player.att += 2;
                player.def += 2;
                player.hp = player.maxhp;
            }
        }
        else if (level[player.pos.y][player.pos.x] == 'M')
        {
            mon = monsters[player.pos];
            bool firstTurn = true;
            if (ornas["HU"])
                player.hp = player.maxhp;
            while (player.hp > 0 && mon.hp > 0)
            {
                // player attack
                int boost = 1;
                if (firstTurn && ornas["CO"])
                {
                    if (ornas["DX"])
                        boost = 3;
                    else
                        boost = 2;
                }
                int playeratt = player.att;
                if (player.hasweapon)
                    playeratt += player.wp.att;
                int playerdef = player.def;
                if (player.hasarmor)
                    playerdef += player.amr.def;
                mon.hp -= max(1, (playeratt)*boost - mon.def);
                if (mon.hp <= 0)
                    break;
                if (!(firstTurn && ornas["HU"]))
                {
                    player.hp -= max(1, mon.att - playerdef);
                }
                firstTurn = false;
            }
            if (player.hp <= 0)
                goto death;
            level[player.pos.y][player.pos.x] = '.';
            if (ornas["HR"])
                player.hp = min(player.maxhp, player.hp + 3);
            float boost = 1;
            if (ornas["EX"])
                boost = 1.2f;
            player.xp += mon.xp * boost;
            if (player.xp >= 5 * player.lv)
            {
                player.lv++;
                player.xp = 0;
                player.maxhp += 5;
                player.att += 2;
                player.def += 2;
                player.hp = player.maxhp;
            }
            win = true;
            break;
        }

        continue;

    death:
        if (ornas["RE"])
        {
            int ornassize = player.ornaments.size();
            int i;
            for (i = 0; i < ornassize; i++)
            {
                if (player.ornaments[i].type.compare("RE") == 0)
                {
                    break;
                }
            }
            player.ornaments.erase(player.ornaments.begin() + i);
            player.pos.x = plgenx;
            player.pos.y = plgeny;
            player.hp = player.maxhp;
            mon.hp = mon.maxhp;
        }
        else
        {
            dead = true;
            break;
        }
    }

    // output
    string deathreason;
    if (level[player.pos.y][player.pos.x] == '^')
        deathreason = "SPIKE TRAP";
    else
        deathreason = mon.name;
    if (!dead)
        level[player.pos.y][player.pos.x] = '@';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << level[i][j];
        cout << "\n";
    }
    cout << "Passed Turns : " << turns << "\n";
    cout << "LV : " << player.lv << "\n";
    cout << "HP : " << max(player.hp, 0) << "/" << player.maxhp << "\n";
    cout << "ATT : " << player.att << "+" << (player.hasweapon ? player.wp.att : 0) << "\n";
    cout << "DEF : " << player.def << "+" << (player.hasarmor ? player.amr.def : 0) << "\n";
    cout << "EXP : " << player.xp << "/" << player.lv * 5 << "\n";
    if (dead)
        cout << "YOU HAVE BEEN KILLED BY " << deathreason << "..";
    else if (win)
        cout << "YOU WIN!";
    else
        cout << "Press any key to continue.";
    return 0;
}
