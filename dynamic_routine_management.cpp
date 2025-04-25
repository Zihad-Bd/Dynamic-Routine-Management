#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)
#define ll long long
#define ull unsigned long long
#define dbl double
ll Toggle(ll n, ll i) { return (n ^ (1ll << i)); }
bool Check(ll N, ll pos) { return (bool)(N & (1ll << pos)); }
ll Set(ll n, ll i) { return (n | (1ll << i)); }
ll Reset(ll n, ll i) { return (n & (~(1ll << i))); }
#define fo(a, x, y)                  \
    for (int i = (x); i <= (y); ++i) \
    {                                \
        cout << a[i] << " ";         \
    }                                \
    cout << endl;
#define me(arr, val) memset(arr, val, sizeof arr)
#define INF INT_MAX
#define INFD DBL_MAX
#define INFL LLONG_MAX
#define f first
#define s second
#define pra(a)             \
    for (auto i : a)       \
    {                      \
        cout << i << endl; \
    }
#define all2(a, start, n) a.begin() + start, a.begin() + start + n
#define all(a) a.begin(), a.end()
#define eb emplace_back
#define em emplace
#define pb push_back
#define sz() size()
#define fl fflush(stdout)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
int SIZE(T(&t))
{
    return t.size();
}
template <typename T, size_t N>
int SIZE(T (&t)[N])
{
    return N;
}
string to_string(char t)
{
    return "'" + string({t}) + "'";
}
string to_string(bool t)
{
    return t ? "true" : "false";
}
string to_string(const string &t, int x1 = 0, int x2 = 1e9)
{
    string ret = "";
    for (int i = min(x1, SIZE(t)), _i = min(x2, SIZE(t) - 1); i <= _i; ++i)
    {
        ret += t[i];
    }
    return '"' + ret + '"';
}
string to_string(const char *t)
{
    string ret(t);
    return to_string(ret);
}
template <size_t N>
string to_string(const bitset<N> &t, int x1 = 0, int x2 = 1e9)
{
    string ret = "";
    for (int i = min(x1, SIZE(t)); i <= min(x2, SIZE(t) - 1); ++i)
    {
        ret += t[i] + '0';
    }
    return to_string(ret);
}
template <typename T, typename... Coords>
string to_string(const T(&t), int x1 = 0, int x2 = 1e9, Coords... C);
template <typename T, typename S>
string to_string(const pair<T, S> &t)
{
    return "(" + to_string(t.first) + ", " + to_string(t.second) + ")";
}
template <typename T, typename... Coords>
string to_string(const T(&t), int x1, int x2, Coords... C)
{
    string ret = "[";
    x1 = min(x1, SIZE(t));
    auto e = begin(t);
    advance(e, x1);
    for (int i = x1, _i = min(x2, SIZE(t) - 1); i <= _i; ++i)
    {
        ret += to_string(*e, C...) + (i != _i ? ", " : "");
        e = next(e);
    }
    return ret + "]";
}
template <int Index, typename... Ts>
struct print_tuple
{
    string operator()(const tuple<Ts...> &t)
    {
        string ret = print_tuple<Index - 1, Ts...>{}(t);
        ret += (Index ? ", " : "");
        return ret + to_string(get<Index>(t));
    }
};
template <typename... Ts>
struct print_tuple<0, Ts...>
{
    string operator()(const tuple<Ts...> &t)
    {
        return to_string(get<0>(t));
    }
};
template <typename... Ts>
string to_string(const tuple<Ts...> &t)
{
    const auto Size = tuple_size<tuple<Ts...>>::value;
    return print_tuple<Size - 1, Ts...>{}(t);
}
void dbgr() { ; }
template <typename Heads, typename... Tails>
void dbgr(Heads H, Tails... T)
{
    cerr << to_string(H) << " | ";
    dbgr(T...);
}
void dbgs() { ; }
template <typename Heads, typename... Tails>
void dbgs(Heads H, Tails... T)
{
    cerr << H << " ";
    dbgs(T...);
}
// #undef LOCAL
#ifdef LOCAL
#define dbgv(...) cerr << to_string(__VA_ARGS__) << endl;
#define dbga(...)                         \
    cerr << "[" << #__VA_ARGS__ << "]: "; \
    dbgv(__VA_ARGS__);
#define dbgr(...)      \
    dbgr(__VA_ARGS__); \
    cerr << endl;
#define dbg(...)                          \
    cerr << "[" << #__VA_ARGS__ << "]: "; \
    dbgr(__VA_ARGS__);
#else
#define dbgv(...) 42
#define dbga(...) 42
#define dbgr(...) 42
#define dbg(...) 42
#endif
ll bigMod(ll x, ll y, ll M)
{
    ll res = 1;
    x = x % M;
    while (y)
    {
        if (y % 2)
        {
            res = (res * x) % M;
            --y;
        }
        else
        {
            x = (x * x) % M;
            y /= 2;
        }
    }
    return res;
}
int dx[] = {0, 0, -1, +1}; // vertical horizontal
int dy[] = {-1, +1, 0, 0}; // vertical horizontal
// int dx[]={+1,+1,-1,-1,+2,-2,+2,-2};//knights move
// int dy[]={+2,-2,+2,-2,+1,+1,-1,-1};//knights move
// int dx[]={+1,-1,0,0,+1,+1,-1,-1};//vertical horizontal diagonal
// int dy[]={0,0,+1,-1,-1,+1,+1,-1};//vertical horizontal diagonal
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
typedef tree<pair<string, int>, null_type, less<pair<string, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;
typedef pair<int, int> ii;
/// Random number generator ///
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
///  for 64 bit use above
/// uniform_int_distribution<int>(l,r)(rng)
///  10 digit random primes ///
/*5915587277
1500450271
3267000013
5754853343
4093082899
9576890767
3628273133

2860486313
5463458053
3367900313*/

unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
default_random_engine gen(seed1); // gen(time(NULL));

int randd(int a, int b)
{
    std::uniform_int_distribution<int> dis(a, b);
    return dis(gen);
}

long long randd(long long a, long long b)
{
    std::uniform_int_distribution<long long> dis(a, b);
    return dis(gen);
}

long double randd(long double a, long double b)
{
    std::uniform_real_distribution<long double> dis(a, b);
    return dis(gen);
}

#define MOD 1000000007ll
#define N 100005

struct teacherInfo
{
    string abbreviation;
    vector<pair<string, int>> classes[7];
};

struct routineInfo
{
    string courseCode;
    string teachersAbbreviation;
    routineInfo()
    {
        courseCode = "";
        teachersAbbreviation = "";
    }
};

int numOfSemister, numOfTeacher, numOfWorkDay, numOfRoutine, totalSlots;
string whichSemister, nameOfTheUniversity, nameOfTheDepartment;
pair<int, int> gapPeriod; // gapPeriod.f = id of which day
                          // gapPeriod.s = id of timeSlot

vector<teacherInfo> teacher;
vector<pair<int, int>> routineUnfitness;
routineInfo routine[2100][7][7][8];
map<string, string> courseName, teacherName;
map<string, double> courseCredit;
map<string, int> numberOfTimeSlot, dayId, teacherLevel, totalSlotForACourse,
    totalWorkingSlotInAWeekOfATeacher;
map<int, string> day;
map<int, int> startTime, startTimeId;
map<string, vector<string>> assignedTeacher; // only the lab courses are count
int totalWorkingSlotInAWeekOfAStudent[9];
map<pair<string, string>, int> totalClassOfACourse[8][5];

void takeTeacherInfo()
{
    cout << "Please enter the number of teacher = ";
    cin >> numOfTeacher;
    cout << "\n";
    map<string, bool> takenLab;
    cout << "For each teacher please enter the following information..." << "\n";
    for (int i = 0; i < numOfTeacher; ++i)
    {
        teacherInfo info1;
        char name[100];
        cout << "Please enter the name of the teacher = ";
        scanf(" %[^\n]s", name);
        cout << "\n";
        int level;
        cout << "Please enter the abbreviation of the teacher = ";
        cin >> info1.abbreviation;
        cout << "\n";
        cout << "Please enter the seniority level of the teacher(1 - 4, from 1 to 4 the seniority is increased) = ";
        cin >> level;
        cout << "\n";
        teacherName[info1.abbreviation] = name;
        teacherLevel[info1.abbreviation] = level;
        // dbg(info1.abbreviation, teacherName[info1.abbreviation]);
        cout << "Please enter the required information from 1st year for this teacher..." << "\n";
        for (int j = 0; j < numOfSemister; ++j)
        {
            int numOfTakenCourse;
            cout << "Please enter the number of taken course in this year = ";
            cin >> numOfTakenCourse;
            cout << "\n";
            // dbg(numOfTakenCourse);
            cout << "please enter following required information for each course..." << "\n";
            while (numOfTakenCourse--)
            {
                string courseCode;
                int numOfClasses;
                cout << "Please enter the course code = ";
                cin >> courseCode;
                cout << "\n";
                cout << "Please enter the number of totalClasses in a week of this course = ";
                cin >> numOfClasses;
                    // dbg(courseCode, numOfClasses);
                info1.classes[j]
                .eb(courseCode, numOfClasses);
                if (courseCode.back() == '2')
                    assignedTeacher[courseCode].eb(info1.abbreviation);
                totalWorkingSlotInAWeekOfATeacher[info1.abbreviation] +=
                    numOfClasses * numberOfTimeSlot[courseCode];
                if (courseCode.back() == '1')
                {
                    totalClassOfACourse[j][numberOfTimeSlot[courseCode]][{courseCode,
                                                                          info1.abbreviation}] += numOfClasses;
                }
                else if (!takenLab[courseCode])
                {
                    totalClassOfACourse[j][numberOfTimeSlot[courseCode]][{courseCode,
                                                                          info1.abbreviation}] += numOfClasses;
                    takenLab[courseCode] = 1;
                }
            }
            // dbg(info1.classes[j]);
        }
        teacher.eb(info1);
    }
}

void takeCourseInfo()
{
    // dbg("Here");
    cout << "Please enter the course information from 1st year..." << "\n";
    for (int i = 0; i < numOfSemister; ++i)
    {
        cout << "Please enter the number of course of this year = ";
        int numOfCourse;
        cin >> numOfCourse;
        cout << "\n";
        // dbg(numOfCourse);
        cout << "For each course please enter the following required information..." << "\n";
        while (numOfCourse--)
        {
            char name[100];
            scanf(" %[^\n]s", name);
            string code;
            double credit;
            int numOfSlot;
            cout << "Enter the course code = ";
            cin >> code;
            cout << "\n";
            cout << "Enter the credit = ";
            cin >> credit;
            cout << "\n";
            cout << "Enter the number of time slot the course taken = ";
            cin >> numOfSlot;
            cout << "\n";
            courseName[code] = name;
            courseCredit[code] = credit;
            numberOfTimeSlot[code] = numOfSlot;
            // dbg(courseName[code], code, credit, numOfSlot);
        }
    }
}

void mappingDays()
{
    cout << "Please enter the number of work days = ";
    cin >> numOfWorkDay;
    cout << "\n";
    // dbg(numOfWorkDay);
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        string dayName;
        cout << "Please enter the day name = ";
        cin >> dayName;
        cout << "\n";
        day[i] = dayName;
        dayId[dayName] = i;
        // dbg(i, dayName, day[i]);
    }
}

void mappingTimeSlot()
{
    for (int i = 0; i < 8; ++i)
    {
        if (i < 4)
        {
            startTime[i] = 9 + i;
            startTimeId[9 + i] = i;
        }
        else
        {
            startTime[i] = (9 + i) % 12;
            startTimeId[(9 + i) % 12] = i;
        }
        // dbg(startTime[i]);
    }
}

void takeGapPeriod()
{
    cout << "Please enter the day and time when all the year's classes are off = ";
    string dayName;
    int Time;
    cout << "Please enter the day name = ";
    cin >> dayName;
    cout << "\n";
    cout << "Please enter the time = ";
    cin >> Time;
    cout << "\n";
    gapPeriod.f = dayId[dayName];
    gapPeriod.s = startTimeId[Time];
    // dbg(gapPeriod);
}

void Clear()
{
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        for (int j = 0; j < numOfSemister; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                routine[numOfRoutine][i][j][k].courseCode = "";
                routine[numOfRoutine][i][j][k].teachersAbbreviation = "";
            }
        }
    }
}

bool isInsertable(int id, int year, int day, int startTime, int alottedSlot) {
    for (int time = startTime; time <= startTime + alottedSlot - 1; ++time) {
        if (time > 7 || time == 4 || (gapPeriod == make_pair(day, time)) ||
        routine[id][day][year][time].courseCode != "") {
            return false;
        }
    }
    return true;
}

bool checkATeacherClassOverlap(int id, int day, int startTime, int alottedSlot) {
    for (int j = startTime; j <= startTime + alottedSlot - 1; ++j) {
        map<string, int> countClassesOfATeacherInSameTimePeriod;
        for (int i = 0; i < numOfSemister; ++i) {
            string code = routine[id][day][i][j].courseCode;
            if (code != "")
            {
                if (code.back() == '1')
                    countClassesOfATeacherInSameTimePeriod[routine[id][day][i][j]
                    .teachersAbbreviation]++;
                else {
                    for (auto teachersAbbreviation : assignedTeacher[code]) {
                        countClassesOfATeacherInSameTimePeriod[teachersAbbreviation]++;
                    }
                }
            }
        }
        for (auto element : countClassesOfATeacherInSameTimePeriod) {
            if (element.s > 1) {
                return true;
            }
        }
    }
    return false;
}

void firstGenerationNoOverlap()
{
    while (numOfRoutine < 1200)
    {
    next:
        map<string, bool> insertCourse;
        map<string, bool> haveClass[7][8];
        for (int i = 0; i < numOfTeacher; ++i)
        {
            for (int j = 0; j < numOfSemister; ++j)
            {
                for (auto x : teacher[i].classes[j])
                {
                    int totalSlot = numberOfTimeSlot[x.f];
                    if (x.f.back() == '2' && insertCourse[x.f])
                    {
                        continue;
                    }
                    for (int k = 0; k < x.s; ++k)
                    {
                        bool canInsert = 0;
                        for (int l = 0; l < 50; ++l)
                        {
                            int day = randd(0, numOfWorkDay - 1);
                            int startTimeUnit = randd(0, 7);
                            bool invalid = 0;
                            for (int m = startTimeUnit; m <= startTimeUnit +
                                                                 totalSlot - 1;
                                 ++m)
                            {
                                if (x.f.back() == '2')
                                {
                                    for (auto teacherAbbreviation : assignedTeacher[x.f])
                                    {
                                        if (haveClass[day][m][teacherAbbreviation])
                                        {
                                            invalid = 1;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    if (haveClass[day][m][teacher[i].abbreviation])
                                    {
                                        invalid = 1;
                                        break;
                                    }
                                }
                                if (m > 7 || m == 4 || (gapPeriod == make_pair(day, m)) ||
                                    routine[numOfRoutine][day][j][m].courseCode != "")
                                {
                                    invalid = 1;
                                    break;
                                }
                            }
                            if (!invalid)
                            {
                                for (int m = startTimeUnit; m <= startTimeUnit +
                                                                     totalSlot - 1;
                                     ++m)
                                {
                                    routine[numOfRoutine][day][j][m].courseCode = x.f;
                                    routine[numOfRoutine][day][j][m].teachersAbbreviation = teacher[i].abbreviation;
                                    if (x.f.back() == '2')
                                    {
                                        for (auto teacherAbbreviation : assignedTeacher[x.f])
                                        {
                                            haveClass[day][m][teacherAbbreviation] = 1;
                                        }
                                    }
                                    else
                                    {
                                        haveClass[day][m][teacher[i].abbreviation] = 1;
                                    }
                                }
                                insertCourse[x.f] = 1;
                                canInsert = 1;
                                break;
                            }
                        }
                        if (!canInsert)
                        {
                            Clear();
                            goto next;
                        }
                    }
                }
            }
        }
        ++numOfRoutine;
    }
}

void printCharacter(char character, int n) {
    while (n--) {
        cout << character;
    }
}

void Print(int id)
{
    string mappingYear[8];
    mappingYear[0] = "1st";
    mappingYear[1] = "2nd";
    mappingYear[2] = "3rd";
    mappingYear[3] = "4th";
    for (int i = 4; i <= 6; ++i) {
        mappingYear[i] = "5th";
    }
    string mappingSemister[8];
    mappingSemister[0] = "Even2018";
    mappingSemister[1] = "Even2018";
    mappingSemister[2] = "Even2018";
    mappingSemister[3] = "Even2018";
    mappingSemister[4] = "1st2017";
    mappingSemister[5] = "2nd2017";
    mappingSemister[6] = "3rd2016";
    cout << "Routine " << id + 1 << "\n";
    printCharacter(' ', (91 - nameOfTheUniversity.length()) / 2);
    cout << nameOfTheUniversity << "\n";
    nameOfTheDepartment = "Department of " + nameOfTheDepartment;
    printCharacter(' ', (91 - nameOfTheDepartment.length()) / 2);
    cout << nameOfTheDepartment << "\n\n";
    int totalLineInADay = numOfSemister * 3 + numOfSemister - 1;
    printCharacter('|', 1);
    printCharacter('-', 3);
    printCharacter('|', 1);
    printCharacter('-', 4);
    printCharacter('|', 1);
    printCharacter('-', 8);
    printCharacter('|', 1);
    for (int slot = 0; slot <= 7; ++slot) {
        if (slot == 4) {
            printCharacter('-', 1);
            printCharacter('|', 1);
        } else {
            printCharacter('-', 9);
            printCharacter('|', 1);
        }
    }
    cout << "\n";
    printCharacter('|', 1);
    cout << "Day";
    printCharacter('|', 1);
    cout << "Year";
    printCharacter('|', 1);
    printCharacter(' ', 2);
    cout << "Sem.";
    printCharacter(' ', 2);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "09:05-";
    printCharacter(' ', 2);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "10:05-";
    printCharacter(' ', 2);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "11:05-";
    printCharacter(' ', 2);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "12:05-";
    printCharacter(' ', 2);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "02:05-";
    printCharacter(' ', 2);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "03:05-";
    printCharacter(' ', 2);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "04:05-";
    printCharacter(' ', 2);
    printCharacter('|', 1);
    cout << "\n";
    printCharacter('|', 1);
    printCharacter(' ', 3);
    printCharacter('|', 1);
    printCharacter(' ', 4);
    printCharacter('|', 1);
    printCharacter(' ', 8);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "10:00";
    printCharacter(' ', 3);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "11:00";
    printCharacter(' ', 3);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "12:00";
    printCharacter(' ', 3);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "01:00";
    printCharacter(' ', 3);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "03:00";
    printCharacter(' ', 3);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "04:00";
    printCharacter(' ', 3);
    printCharacter('|', 1);
    printCharacter(' ', 1);
    cout << "05:00";
    printCharacter(' ', 3);
    printCharacter('|', 1);
    cout << "\n";
    for (int i = 0; i < numOfWorkDay; ++i) {
        printCharacter('|', 1);
        printCharacter('-', 3);
        printCharacter('|', 1);
        printCharacter('-', 4);
        printCharacter('|', 1);
        printCharacter('-', 8);
        printCharacter('|', 1);
        for (int slot = 0; slot <= 7; ++slot)
        {
            if (slot == 4)
            {
                printCharacter(' ', 1);
                printCharacter('|', 1);
            }
            else
            {
                printCharacter('-', 9);
                printCharacter('|', 1);
            }
        }
        cout << "\n";
        int totalLineTillNow = 0;
        for (int j = 0; j < numOfSemister; ++j) {
            for (int line = 1; line <= 3; ++line) {
                printCharacter('|', 1);
                ++totalLineTillNow;
                if ((totalLineInADay + 1) / 2 == totalLineTillNow) {
                    for (int k = 0; k < 3; ++k) {
                        cout << day[i][k];
                    }
                } else {
                    printCharacter(' ', 3);
                }
                printCharacter('|', 1);
                if (line == 2) {
                    cout << mappingYear[j] << " ";
                } else {
                    printCharacter(' ', 4);
                }
                printCharacter('|', 1);
                if (line == 2) {
                    cout << mappingSemister[j];
                    printCharacter(' ', 8 - mappingSemister[j].length());
                } else {
                    printCharacter(' ', 8);
                }
                printCharacter('|', 1);
                for (int slot = 0; slot <= 7; ++slot) {
                    if (slot == 4) {
                        printCharacter(' ', 1);
                        printCharacter('|', 1);
                        continue;
                    }
                    string code = routine[id][i][j][slot].courseCode;
                    if (code == "")
                    {
                        printCharacter(' ', 9);
                        printCharacter('|', 1);
                        continue;
                    }
                    int totalHorizontalSpace = numberOfTimeSlot[code] * 9
                        + numberOfTimeSlot[code] - 1;
                    int remainingSpace;
                    string needToPrint;
                    if (line == 1) {
                        needToPrint = code;
                    } else if (line == 2) {
                        if (code.back() == '1') {
                            needToPrint =
                            routine[id][i][j][slot].teachersAbbreviation;
                        } else {
                            for (int l = 0; l < 2; ++l) {
                                needToPrint += assignedTeacher[code][l];
                                if (l == 0) {
                                    needToPrint += ',';
                                }
                            }
                        }
                    } else {
                        if (code.back() == '2') {
                            for (int l = 2; l < assignedTeacher[code].sz(); ++l)
                            {
                                needToPrint += assignedTeacher[code][l];
                                if (l < assignedTeacher[code].sz() - 1)
                                {
                                    needToPrint += ',';
                                }
                            }
                        }
                    }
                    remainingSpace = totalHorizontalSpace - needToPrint.length();
                    printCharacter(' ', remainingSpace / 2);
                    cout << needToPrint;
                    printCharacter(' ', (remainingSpace + 1) / 2);
                    printCharacter('|', 1);
                    slot += numberOfTimeSlot[code] - 1;
                }
                cout << "\n";
            }
            printCharacter('|', 1);
            ++totalLineTillNow;
            if ((totalLineInADay + 1) / 2 == totalLineTillNow)
            {
                for (int k = 0; k < 3; ++k)
                {
                    cout << day[i][k];
                }
            }
            else
            {
                if (j == numOfSemister - 1) {
                    printCharacter('-', 3);
                } else {
                    printCharacter(' ', 3);
                }
            }
            printCharacter('|', 1);
            printCharacter('-', 4);
            printCharacter('|', 1);
            printCharacter('-', 8);
            printCharacter('|', 1);
            for (int slot = 0; slot <= 7; ++slot)
            {
                if (slot == 4)
                {
                    printCharacter(' ', 1);
                    printCharacter('|', 1);
                }
                else
                {
                    printCharacter('-', 9);
                    printCharacter('|', 1);
                }
            }
            cout << "\n";
        }
        if (i == numOfWorkDay - 1) {
            break;
        }
        printCharacter('|', 1);
        printCharacter('_', 57);
        printCharacter('|', 1);
        printCharacter(' ', 1);
        printCharacter('|', 1);
        printCharacter('_', 29);
        printCharacter('|', 1);
        cout << "\n";
    }
        /*     for (int i = 0; i < numOfWorkDay; ++i)
            {
                for (int j = 0; j < numOfSemister; ++j)
                {
                    for (int k = 0; k < 8; ++k)
                    {
                        if (routine[id][i][j][k].courseCode == "")
                        {
                            cout << " @ ";
                        }
                        else
                            cout << routine[id][i][j][k].courseCode << " "
                                 << routine[id][i][j][k].teachersAbbreviation << " ";
                    }
                    cout << "\n";
                }
                cout << "\n\n";
            } */
}

void findtotalWorkingSlotInAWeekOfAStudent()
{
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        for (int j = 0; j < numOfSemister; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                if (routine[0][i][j][k].courseCode != "")
                {
                    totalWorkingSlotInAWeekOfAStudent[j]++;
                    ++totalSlots;
                }
            }
        }
    }
}

int teachersPriority(int id)
{
    int unfitness = 0;
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        for (int j = 0; j < numOfSemister; ++j)
        {
            if (routine[id][i][j][0].courseCode.back() == '1')
            {
                if (teacherLevel[routine[id][i][j][0].teachersAbbreviation] == 4)
                {
                    unfitness += 60;
                }
                else if (teacherLevel[routine[id][i][j][0].teachersAbbreviation] == 3)
                {
                    unfitness += 5;
                }
            }
            else
            {
                for (auto teacher : assignedTeacher[routine[id][i][j][0].courseCode])
                {
                    if (teacherLevel[teacher] == 4)
                    {
                        unfitness += 30;
                    }
                }
            }
        }
    }
    return unfitness;
}

int repeatingClassInADay(int id)
{
    int unfitness = 0;
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        for (int j = 0; j < numOfSemister; ++j)
        {
            unordered_map<string, int> mp;
            for (int k = 0; k < 8; ++k)
            {
                if (routine[id][i][j][k].courseCode != "")
                    mp[routine[id][i][j][k].courseCode]++;
            }
            for (auto course : mp)
            {
                if (course.f.back() == '2')
                {
                    int cnt = course.s / numberOfTimeSlot[course.f];
                    if (cnt >= 2)
                    {
                        unfitness += 500;
                    }
                }
                else
                {
                    if (course.s == 2)
                    {
                        unfitness += ((double)1 / totalSlotForACourse[course.f]) * (double)200;
                    }
                }
            }
        }
    }
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        for (int j = 0; j < numOfSemister; ++j)
        {
            map<pair<string, string>, int> mp;
            for (int k = 0; k < 8; ++k)
            {
                if (routine[id][i][j][k].courseCode.back() == '1')
                {
                    mp[{routine[id][i][j][k].courseCode,
                        routine[id][i][j][k].teachersAbbreviation}]++;
                }
            }
            for (auto course : mp)
            {
                if (course.s > 1)
                {
                    unfitness += 500;
                }
            }
        }
    }
    return unfitness;
}

int consequtiveClassOfATeacher(int id)
{
    int unfitness = 0;
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        map<string, vector<pair<int, int>>> mp;
        for (int j = 0; j < numOfSemister; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                string code = routine[id][i][j][k].courseCode;
                if (code != "")
                {
                    if (code.back() == '2')
                    {
                        for (auto teacher : assignedTeacher[code])
                        {
                            mp[teacher].eb(k, numberOfTimeSlot[code]);
                        }
                    }
                    else
                    {
                        mp[routine[id][i][j][k].teachersAbbreviation]
                            .eb(k, 1);
                    }
                }
            }
        }
        for (auto teacher : mp)
        {
            for (int p = 0; p < teacher.second.sz(); ++p)
            {
                int shouldNext = teacher.second[p].f + teacher.second[p].s;
                if (p + 1 < teacher.second.sz() &&
                    teacher.second[p + 1].f == shouldNext)
                {
                    unfitness += (teacher.second[p].s == 1 ? 30 : 60) +
                                 (teacher.second[p + 1].s == 1 ? 30 : 60);
                }
            }
        }
    }
    return unfitness;
}

int consequtiveClassOfAStudent(int id)
{
    int unfitness = 0;
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        for (int j = 0; j < numOfSemister; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                string code = routine[id][i][j][k].courseCode;
                if (code != "" && code.back() == '2')
                {
                    int shouldNext = k + numberOfTimeSlot[code];
                    if (shouldNext < 8 && routine[id][i][j][shouldNext].courseCode != "" &&
                        routine[id][i][j][shouldNext].courseCode.back() == '2')
                    {
                        unfitness += 70;
                    }
                    k += numberOfTimeSlot[code] - 1;
                }
            }
        }
    }
    return unfitness;
}

int findUnfitnessForUnusualClassOfAStudent(int id)
{
    int unfitness = 0;
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        for (int j = 0; j < numOfSemister; ++j)
        {
            int totalClassInADay = 0;
            for (int k = 0; k < 8; ++k)
            {
                if (routine[id][i][j][k].courseCode != "")
                {
                    ++totalClassInADay;
                }
            }
            int optimalAverageSlotInADayOfAStudent =
                (round((double)totalWorkingSlotInAWeekOfAStudent[j] / numOfWorkDay));
            unfitness += max(0,
                             (abs(totalClassInADay - optimalAverageSlotInADayOfAStudent) - 1) * 20);
        }
    }
    return unfitness;
}

int findUnfitnessForUnusualClassOfATeacher(int id)
{
    int unfitness = 0;
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        map<string, int> mp;
        for (int j = 0; j < numOfSemister; ++j)
        {
            int totalClassInADay = 0;
            for (int k = 0; k < 8; ++k)
            {
                string code = routine[id][i][j][k].courseCode;
                if (code != "")
                {
                    if (code.back() == '1')
                    {
                        mp[routine[id][i][j][k].teachersAbbreviation]++;
                    }
                    else
                    {
                        for (auto teacher : assignedTeacher[code])
                        {
                            mp[teacher]++;
                        }
                    }
                }
            }
        }
        for (auto teacher : mp)
        {
            int optimalAverageSlotInADayOfATeacher =
                (round((double)totalWorkingSlotInAWeekOfATeacher[teacher.f] / numOfWorkDay));
            unfitness += max(0,
                             (abs(teacher.s - optimalAverageSlotInADayOfATeacher) - 1) * 25);
            // dbg(teacher, totalWorkingSlotInAWeekOfATeacher[teacher.f], optimalAverageSlotInADayOfATeacher, unfitness);
        }
    }
    return unfitness;
}

int checkOverlap(int id)
{
    int unfitness = 0;
    int totalSlotsForThisRoutine = 0;
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        for (int j = 0; j < numOfSemister; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                if (routine[id][i][j][k].courseCode != "")
                {
                    ++totalSlotsForThisRoutine;
                }
            }
        }
    }
    /* if (numOfRoutine == 25)
        dbg(totalSlots, totalSlotsForThisRoutine); */
    if (totalSlots != totalSlotsForThisRoutine)
    {
        //Print(id);
        //dbg("first type of overlap");
        unfitness = 1e6;
    }
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            map<string, int> totalClassOfATeacherInThisDayInThisPeriod;
            for (int k = 0; k < numOfSemister; ++k)
            {
                string code = routine[id][i][k][j].courseCode;
                string abbreviation = routine[id][i][k][j].teachersAbbreviation;
                if (code != "")
                {
                    if (code.back() == '1')
                    {
                        totalClassOfATeacherInThisDayInThisPeriod[abbreviation]++;
                    }
                    else
                    {
                        /*  if (numOfRoutine == 25)
                             //dbg(code); */
                        for (auto teacherAbbreviation : assignedTeacher[code])
                        {
                            totalClassOfATeacherInThisDayInThisPeriod[teacherAbbreviation]++;
                            /*  if (numOfRoutine == 25)
                                 //dbg(teacherAbbreviation); */
                        }
                    }
                }
            }

            for (auto teacher : totalClassOfATeacherInThisDayInThisPeriod)
            {
                if (teacher.s > 1)
                {
                    //Print(id);
                    dbg(teacher.f, teacher.s);
                    unfitness += 1e6;
                    return unfitness;
                }
            }
        }
    }
    return unfitness;
}

int findUnfitness(int id)
{
    int unfitness = 0;
    unfitness += teachersPriority(id);
    // dbg(unfitness);
    unfitness += repeatingClassInADay(id);
    // dbg(unfitness);
    unfitness += consequtiveClassOfATeacher(id);
    // dbg(unfitness);
    unfitness += consequtiveClassOfAStudent(id);
    // dbg(unfitness);
    unfitness += findUnfitnessForUnusualClassOfAStudent(id);
    // dbg(unfitness);
    unfitness += findUnfitnessForUnusualClassOfATeacher(id);
    // dbg(unfitness);
    unfitness += checkOverlap(id);
    // dbg(unfitness);
    return unfitness;
}

void findTotalClassOfACourse()
{
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        for (int j = 0; j < numOfSemister; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                if (routine[0][i][j][k].courseCode != "")
                {
                    totalSlotForACourse[routine[0][i][j][k].courseCode]++;
                }
            }
        }
    }
}

indexed_set findFilledSlots(int id, int whichSemister, int needSlotForEachClass)
{
    indexed_set filledSlots;
    for (int i = 0; i < numOfWorkDay; ++i)
    {
        for (int k = 0; k < 8; ++k)
        {
            string code = routine[id][i][whichSemister][k].courseCode;
            if (code != "")
            {
                if (numberOfTimeSlot[code] == needSlotForEachClass)
                {
                    filledSlots.insert({i, k});
                    k += needSlotForEachClass - 1;
                }
            }
        }
    }
    return filledSlots;
}

bool canInsert(int id, int day, int whichSemister, int startTime, int slotNeed,
               map<pair<string, string>, int> &mp)
{
    string code = routine[id][day][whichSemister][startTime].courseCode;
    string abbreviation =
        routine[id][day][whichSemister][startTime].teachersAbbreviation;
    if (code != "" && numberOfTimeSlot[code] == slotNeed &&
        mp[{code, abbreviation}])
    {
        for (int l = startTime; l <= startTime + slotNeed - 1; ++l)
        {
            routine[numOfRoutine][day][whichSemister][l].courseCode = code;
            routine[numOfRoutine][day][whichSemister][l].teachersAbbreviation =
                routine[id][day][whichSemister][startTime].teachersAbbreviation;
        }
        pair<string, string> p = {code,
                                  routine[id][day][whichSemister][startTime].teachersAbbreviation};
        --mp[p];
        if (!mp[p])
        {
            mp.erase(p);
        }
        return true;
    }
    return false;
}

bool checkSameCourseSameTeacherInADay(int id, int year, int day, string code, string
teacherAbbreviation) {
    int Count = 0;
    for (int i = 0; i < 8; ++i) {
        string presentCode = routine[id][day][year][i].courseCode;
        if (presentCode != "" && presentCode == code && routine[id][day][year][i]
        .teachersAbbreviation == teacherAbbreviation) {
            ++Count;
            i += numberOfTimeSlot[code] - 1;
        }
    }
    return Count > 1;
}
bool checkSameTheoryCourseInADay(int id, int year, int day, string code) {
    if (code.back() == '2') {
        return 0;
    }
    int Count = 0;
    for (int i = 0; i < 8; ++i) {
        string presentCode = routine[id][day][year][i].courseCode;
        if (presentCode != "" && presentCode == code) {
            ++Count;
        }
    }
    return Count > 1;
}

void Erase(int id, int day, int year, int startTime, int slotNeed) {
    for (int l = startTime; l <= startTime + slotNeed - 1; ++l)
    {
        routine[id][day][year][l].courseCode = "";
        routine[id][day][year][l].teachersAbbreviation = "";
    }
}

void Insert(int id, int day, int year, int startTime, int slotNeed, string 
teacherAbbreviation, string code)
{
    for (int l = startTime; l <= startTime +
        slotNeed - 1; ++l)
    {
        routine[id][day][year][l].courseCode = code;
        routine[id][day][year][l].teachersAbbreviation =
            teacherAbbreviation;
    }
}

map<string, bool> gatherAlottedTeachers(int id, int day, int year, int startTime) {
    map<string, bool> alottedTeacher;
    string code = routine[id][day][year][startTime].courseCode;
    if (code != "") {
        if (code.back() == '1') {
            alottedTeacher[routine[id][day][year][startTime].teachersAbbreviation] = 1;
        } else {
            for (auto teacherAbbreviation : assignedTeacher[code]) {
                alottedTeacher[teacherAbbreviation] = 1;
            }
        }
    }
    return alottedTeacher;
}

bool checkConsequtiveClassOfTeachers(int id, int year, int day,
    int startTime, string code, int neighbourStartTime)
{
    if (neighbourStartTime >= 0 && neighbourStartTime <= 7 &&
        routine[id][day][year][neighbourStartTime].courseCode != "")
    {
        map<string, bool> alottedTeacher1 = gatherAlottedTeachers(id, day, year, startTime);
        map<string, bool> alottedTeacher2 = gatherAlottedTeachers(id, day, year,
         neighbourStartTime);
        for (auto teacher1 : alottedTeacher1) {
            for (auto teacher2 : alottedTeacher2) {
                if (teacher1 == teacher2) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

vector<vector<pair<int, int>>> findEmptySlots(int id)
{
    vector<vector<pair<int, int>>> emptySlots(numOfSemister, vector<pair<int, int>>(0));
    for (int i = 0; i < numOfWorkDay; ++i) {
        for (int j = 0; j < numOfSemister; ++j) {
            for (int k = 0; k < 8; ++k) {
                if (routine[id][i][j][k].courseCode == "" && make_pair(i, k) !=
                gapPeriod && k != 4) {
                    emptySlots[j].eb(i, k);
                }
            }
        }
    }
    return emptySlots;
}

void addEmptySlots(vector<vector<pair<int, int>>> &emptySlots, int day,
int year, int startTime, int slotNeed) {
    for (int n = startTime; n <= startTime +
    slotNeed - 1; ++n)
    {
        emptySlots[year].eb(day, n);
    }
}

void removeEmptySlots(vector<vector<pair<int, int>>> &emptySlots, int day,
int year, int startTime, int slotNeed) {
    for (int p = 0; p < emptySlots[year].sz(); ++p)
    {
        if (emptySlots[year][p].f == day &&
            emptySlots[year][p].s >= startTime &&
            emptySlots[year][p].s <= startTime + slotNeed - 1)
        {
            emptySlots[year].erase(emptySlots[year].begin() + p);
            --p;
        }
    }
}

void secondGenerationFixSameCourseSameTeacherInADay(int id) {
    vector<vector<pair<int, int>>> emptySlots = findEmptySlots(id);
    for (int i = 0; i < numOfWorkDay; ++i) {
        for (int j = 0; j < numOfSemister; ++j) {
            map<pair<string, string>, int> classStartTime;
            for (int k = 0; k < 8; ++k) {
                string code = routine[id][i][j][k].courseCode;
                string teacherAbbreviation =
                    routine[id][i][j][k].teachersAbbreviation;
                int slotNeed = numberOfTimeSlot[code];
                if (code != "") {
                    auto it = classStartTime.find({code,
                     teacherAbbreviation});
                    if (it == classStartTime.end()) {
                        classStartTime[{code, teacherAbbreviation}] = k;
                    } else {
                        //dbg(code, teacherAbbreviation);
                        for (int chosen = 0; chosen <= 1; ++chosen) {
                            bool inserted = 0;
                            int startTime;
                            if (chosen == 0) {
                                startTime = it->s;
                            } else {
                                startTime = k;
                            }
                            Erase(id, i, j, startTime, numberOfTimeSlot[code]);
                            addEmptySlots(emptySlots, i, j, startTime, slotNeed);
                            int cntIteration = 0;
                            while (cntIteration < emptySlots[j].sz()) {
                                //dbg(cntIteration);
                                int emptyId = randd(0,
                                emptySlots[j].sz() - 1);
                                int newDay = emptySlots[j][emptyId].f;
                                int newStartTime =
                                emptySlots[j][emptyId].s;
                                if (isInsertable(id, j, newDay, newStartTime, 
                                numberOfTimeSlot[code])) {
                                    bool possible = 1;
                                    Insert(id, newDay, j, newStartTime,
                                    numberOfTimeSlot[code], teacherAbbreviation, code);
                                    removeEmptySlots(emptySlots, newDay, j, newStartTime,
                                    slotNeed);
                                    //cout << "after Insert in 1020" << "\n";
                                    //Print(id);
                                    for (int l = newStartTime; l <= newStartTime +
                                        numberOfTimeSlot[code] - 1; ++l)
                                    {
                                        if (checkATeacherClassOverlap(id, newDay, l, numberOfTimeSlot[code]))
                                        {
                                            possible = 0;
                                            break;
                                        }
                                    }
                                    possible &= !checkSameCourseSameTeacherInADay(id, j,
                                    newDay, code, teacherAbbreviation);
                                    //dbg(possible);
                                    if ( !possible) {
                                        Erase(id, newDay, j, newStartTime,
                                         numberOfTimeSlot[code]);
                                        addEmptySlots(emptySlots, newDay, j, newStartTime, slotNeed);
                                        //cout << "after erase in 1036" << "\n";
                                        //Print(id);
                                        ++cntIteration;
                                    } else {
                                        if (chosen == 0) {
                                            classStartTime[
                                                {code, teacherAbbreviation}] = k;
                                        }
                                        inserted = 1;
                                        goto next;
                                    }
                                }
                            }
                            next:
                            if (inserted) {
                                break;
                            } else {
                                Insert(id, i, j, startTime, numberOfTimeSlot[code],
                                teacherAbbreviation, code);
                                removeEmptySlots(emptySlots, i, j, startTime,
                                slotNeed);
                                //cout << "after Insert in 1054" << "\n";
                                //Print(id);
                            }
                        }
                    }
                    k += numberOfTimeSlot[code] - 1;
                }
            }
        }
    }
}

void thirdGenerationFixSameTheoryCourseInADay(int id)
{
    vector<vector<pair<int, int>>> emptySlots = findEmptySlots(id);
    for (int i = 0; i < numOfWorkDay; ++i) {
        for (int j = 0; j < numOfSemister; ++j) {
            map<string, pair<string, int>> classStartTime;
            for (int k = 0; k < 8; ++k) {
                string code = routine[id][i][j][k].courseCode;
                string presentTeacherAbbreviation =
                    routine[id][i][j][k].teachersAbbreviation;
                int slotNeed = numberOfTimeSlot[code];
                if (code != "" && code.back() == '1') {
                    auto it = classStartTime.find(code);
                    if (it == classStartTime.end()) {
                        classStartTime[code] = {presentTeacherAbbreviation, k};
                    } else {
                        string previousTeacherAbbreviation = it->s.f;
                        //dbg(code, teacherAbbreviation);
                        for (int chosen = 0; chosen <= 1; ++chosen) {
                            bool inserted = 0;
                            int startTime;
                            string insertedTeacherAbbreviation;
                            if (chosen == 0) {
                                startTime = it->s.s;
                                insertedTeacherAbbreviation = previousTeacherAbbreviation;
                            } else {
                                startTime = k;
                                insertedTeacherAbbreviation = presentTeacherAbbreviation;
                            }
                            Erase(id, i, j, startTime, numberOfTimeSlot[code]);
                            addEmptySlots(emptySlots, i, j, startTime, slotNeed);
                            int cntIteration = 0;
                           //cout << "after erase in 1009" << "\n";
                            //Print(id);
                            while (cntIteration < emptySlots[j].sz())
                            {
                                // dbg(cntIteration);
                                int emptyId = randd(0, emptySlots[j].sz() - 1);
                                int newDay = emptySlots[j][emptyId].f;
                                int newStartTime = emptySlots[j][emptyId].s;
                                if (isInsertable(id, j, newDay, newStartTime, 
                                numberOfTimeSlot[code])) {
                                    bool possible = 1;
                                    Insert(id, newDay, j, newStartTime,
                                    numberOfTimeSlot[code], insertedTeacherAbbreviation
                                    , code);
                                    removeEmptySlots(emptySlots, newDay, j, newStartTime,
                                    slotNeed);
                                    //cout << "after Insert in 1020" << "\n";
                                    //Print(id);
                                    possible &= !checkATeacherClassOverlap(id,
                                     newDay, newStartTime, numberOfTimeSlot[code]);
                                    if ( !possible) {
                                        goto Erasing;
                                    }
                                    possible &= !checkSameCourseSameTeacherInADay(id, j,
                                    newDay, code, insertedTeacherAbbreviation);
                                    if ( !possible) {
                                        goto Erasing;
                                    }
                                    possible &= !checkSameTheoryCourseInADay(id, j, newDay,
                                    code);
                                    //dbg(possible);
                                    if ( !possible) {
                                        Erasing:
                                        Erase(id, newDay, j, newStartTime,
                                        slotNeed);
                                        addEmptySlots(emptySlots, newDay, j, newStartTime, slotNeed);
                                        //cout << "after erase in 1036" << "\n";
                                        //Print(id);
                                        ++cntIteration;
                                    } else {
                                        if (chosen == 0) {
                                            classStartTime[code] =
                                             {presentTeacherAbbreviation, k};
                                        }
                                        inserted = 1;
                                        goto next;
                                    }
                                }
                            }
                            next:
                            if (inserted) {
                                break;
                            } else {
                                Insert(id, i, j, startTime, numberOfTimeSlot[code],
                                insertedTeacherAbbreviation, code);
                                removeEmptySlots(emptySlots, i, j, startTime,
                                slotNeed);
                                //cout << "after Insert in 1054" << "\n";
                                //Print(id);
                            }
                        }
                    }
                }
            }
        }
    }
}

void forthGenerationFixConsequtiveClassOfTeachers(int id) {
    vector<vector<pair<int, int>>> emptySlots = findEmptySlots(id);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < numOfWorkDay; ++j) {
            for (int k = 0; k <= 6; ++k) {     
                nextSlot:
                //cout << "k : " << k << "\n";
                if (k > 6) {
                    break;
                }
                for (int l = 0; l < numOfSemister; ++l) {
                    string code = routine[id][j][l][k].courseCode;
                    map<string, bool> alottedTeacher1 = gatherAlottedTeachers(id, j, l, 
                    k);

                    if (code != "" && alottedTeacher1[teacher[i].abbreviation] &&
                    (k - 1 < 0 || routine[id][j][l][k - 1].courseCode != code)) {
                        int k2 = k + numberOfTimeSlot[code];
                        if (k2 > 7 || k2 == 4 || gapPeriod == make_pair(j, k2)) {
                            continue;
                        }
                        for (int m = 0; m < numOfSemister; ++m) {
                            string code2 = routine[id][j][m][k2].courseCode;
                            map<string, bool> alottedTeacher2 = gatherAlottedTeachers(id, 
                            j, m, k2);
                            if (code2 != "" && alottedTeacher2[teacher[i].abbreviation] &&
                            (k2 - 1 < 0 || routine[id][j][l][k2 - 1].courseCode != code2))
                            {
                                //cout << "teacher ab " << teacher[i].abbreviation <<
                                //" k " << k << " k2 " << k2 << "\n";
                                string whichCode, teacherAbbreviation;
                                int startTime, slotNeed, whichYear;
                                for (int chosen = 0; chosen <= 1; ++chosen) {
                                    if (chosen == 0) {
                                        whichYear = l;
                                        startTime = k;
                                        slotNeed = numberOfTimeSlot[code];
                                        whichCode = code;
                                        teacherAbbreviation =
                                        routine[id][j][l][k].teachersAbbreviation;
                                    } else {
                                        whichYear = m;
                                        startTime = k2;
                                        slotNeed = numberOfTimeSlot[code2];
                                        whichCode = code2;
                                        teacherAbbreviation =
                                        routine[id][j][m][k2].teachersAbbreviation;
                                    }
                                    int cntIteration = 0;
                                    Erase(id, j, whichYear, startTime, slotNeed);
                                    addEmptySlots(emptySlots, j, whichYear, startTime, slotNeed);
/*                                     cout << "Erase in 1273"
                                         << "\n";
                                    cout << "day :" << j << " "
                                         << "year :" << whichYear
                                         << " "
                                         << "startTime :" << startTime << "\n";
                                    Print(id); */
                                    while (cntIteration < emptySlots[whichYear].sz()) {
                                        int emptyId = randd(0,
                                        emptySlots[whichYear].sz() - 1);
                                        int newDay = emptySlots[whichYear][emptyId].f;
                                        int newStartTime =
                                         emptySlots[whichYear][emptyId].s;
                                        bool possible = isInsertable(id, whichYear, newDay,
                                        newStartTime, slotNeed);
                                        if (possible) {
                                            Insert(id, newDay, whichYear, newStartTime,
                                            slotNeed, teacherAbbreviation, whichCode);
/*                                             cout << "insert in 1291"
                                                 << "\n";
                                            cout << "newDay :" << newDay << " "
                                                 << "newStartTime :" << newStartTime << "\n";
                                            Print(id); */
                                            removeEmptySlots(emptySlots, newDay, whichYear, newStartTime,
                                            slotNeed);
                                            possible &= !checkATeacherClassOverlap(id,
                                            newDay, newStartTime, slotNeed);
                                            if ( !possible) {
                                                goto Erasing;
                                            }
                                            //cout << "teacher class overlap :" << possible << "\n";
                                            possible &= !checkSameCourseSameTeacherInADay(
                                            id, whichYear, newDay, whichCode, teacherAbbreviation);
                                            if (!possible)
                                            {
                                                goto Erasing;
                                            }
                                            possible &= !checkSameTheoryCourseInADay(
                                            id, whichYear, newDay, whichCode);
                                            if ( !possible)
                                            {
                                                goto Erasing;
                                            }
                                            possible &= !checkConsequtiveClassOfTeachers(
                                            id, whichYear, newDay, newStartTime, whichCode,
                                            newStartTime - 1);
                                            if (!possible)
                                            {
                                                goto Erasing;
                                            }
                                            possible &= !checkConsequtiveClassOfTeachers(
                                            id, whichYear, newDay, newStartTime, whichCode, 
                                            newStartTime + slotNeed);
                                            if (possible) {
                                                k = startTime + slotNeed;
                                                goto nextSlot;
                                            } else {
                                                Erasing:
                                                ++cntIteration;
                                                Erase(id, newDay, whichYear, newStartTime,
                                                slotNeed);
/*                                                 cout << "erase in 1342"
                                                     << "\n";
                                                cout << "newDay :" << newDay << " " << 
                                                "newStartTime :" << newStartTime << "\n";
                                                Print(id); */
                                                addEmptySlots(emptySlots, newDay, whichYear,
                                                newStartTime, slotNeed);
/*                                                 for (int n = newStartTime; n <= newStartTime +
                                                slotNeed - 1; ++n)
                                                {
                                                    emptySlots[whichYear].eb(newDay, n);
                                                } */
                                            }
                                        }
                                    }
                                    Insert(id, j, whichYear, startTime, slotNeed, 
                                    teacherAbbreviation, whichCode);
/*                                     cout << "insert in 1357"
                                         << "\n";
                                    cout << "day :" << j << " " << "startTime :" << startTime <<
                                    "\n";
                                    Print(id); */
                                    removeEmptySlots(emptySlots, j, whichYear, startTime,
                                    slotNeed);
/*                                     for (int p = 0; p < emptySlots[whichYear].sz(); ++p)
                                    {
                                        if (emptySlots[whichYear][p].f == j &&
                                        emptySlots[whichYear][p].s >= startTime &&
                                        emptySlots[whichYear][p].s <= startTime + slotNeed - 1)
                                        {
                                            emptySlots[whichYear].erase(emptySlots[whichYear].begin() + p);
                                            --p;
                                        }
                                    } */
                                }
                                k = k + numberOfTimeSlot[code];
                                goto nextSlot;
                            }
                        }
                    }
                }
            }
        }
    }
}

void fifthGenerationFixSeniorTeacherEarlyClass(int id) {
    vector<vector<pair<int, int>>> emptySlots = findEmptySlots(id);
    for (int i = 0; i < numOfWorkDay; ++i) {
        for (int j = 0; j < numOfSemister; ++j) {
            bool inserted = 0;
            string code = routine[id][i][j][0].courseCode;
            int slotNeed = numberOfTimeSlot[code];
            string insertedTeacherAbbreviation = routine[id][i][j][0].teachersAbbreviation;
            if (code != "" && code.back() == '1' &&
            teacherLevel[insertedTeacherAbbreviation] >= 3)
            {
                Erase(id, i, j, 0, slotNeed);
                addEmptySlots(emptySlots, i, j, 0, slotNeed);
                int cntIteration = 0;
                while (cntIteration < emptySlots[j].sz())
                {
                    int emptyId = randd(0, emptySlots[j].sz() - 1);
                    int newDay = emptySlots[j][emptyId].f;
                    int newStartTime = emptySlots[j][emptyId].s;
                    if (isInsertable(id, j, newDay, newStartTime,
                    slotNeed))
                    {
                        bool possible = 1;
                        Insert(id, newDay, j, newStartTime,
                        numberOfTimeSlot[code], insertedTeacherAbbreviation, code);
                        removeEmptySlots(emptySlots, newDay, j, newStartTime,
                        slotNeed);
                        possible &= !checkATeacherClassOverlap(id,
                        newDay, newStartTime, slotNeed);
                        if (!possible)
                        {
                            goto Erasing;
                        }
                        possible &= !checkSameCourseSameTeacherInADay(id, j,
                        newDay, code, insertedTeacherAbbreviation);
                        if (!possible)
                        {
                            goto Erasing;
                        }
                        possible &= !checkSameTheoryCourseInADay(id, j, newDay,
                        code);
                        if ( !possible) {
                            goto Erasing;
                        }
                        possible &= !checkConsequtiveClassOfTeachers(
                            id, j, newDay, newStartTime, code,
                            newStartTime - 1);
                        if ( !possible)
                        {
                            goto Erasing;
                        }
                        possible &= !checkConsequtiveClassOfTeachers(
                        id, j, newDay, newStartTime, code,
                        newStartTime + slotNeed);
                        possible &= !(newStartTime == 0);
                        if (!possible)
                        {
                            Erasing:
                            Erase(id, newDay, j, newStartTime,
                            slotNeed);
                            addEmptySlots(emptySlots, newDay, j, newStartTime, slotNeed);
                            ++cntIteration;
                        }
                        else
                        {
                            inserted = 1;
                            goto next;
                        }
                    }
                }
                next:
                if (inserted)
                {
                    break;
                }
                else
                {
                    Insert(id, i, j, 0, slotNeed,
                    insertedTeacherAbbreviation, code);
                    removeEmptySlots(emptySlots, i, j, 0,
                    slotNeed);
                }
            }
        }
    }
}

int main()
{
    cout << "Please enter the name of the University = ";
    char name[100];
    scanf(" %[^\n]s", name);
    nameOfTheUniversity = name;
    cout << "\n";
    cout << "Please enter the name of the department = ";
    scanf(" %[^\n]s", name);
    nameOfTheDepartment = name;
    cout << "\n";
    cout << "Please enter the name of the semister(odd / even / full-year) = ";
    cin >> whichSemister;
    cout << "\n";
    cout << "Please enter the number of total year(for masters consider each semister a year. Example : If there are 3 semister in masters then total year = 4 + 3 = 7) = ";
    cin >> numOfSemister;
    cout << "\n";
    takeCourseInfo();
    takeTeacherInfo();
    mappingDays();
    mappingTimeSlot();
    takeGapPeriod();
    firstGenerationNoOverlap();
    findtotalWorkingSlotInAWeekOfAStudent();
    findTotalClassOfACourse();
    int Min = INF, Min2 = INF, Min3 = INF;
    int bestRoutineId = 0;
    for (int i = 0; i < numOfRoutine; ++i) {
        secondGenerationFixSameCourseSameTeacherInADay(i);
        thirdGenerationFixSameTheoryCourseInADay(i);
        Min = min(Min, findUnfitness(i));
        forthGenerationFixConsequtiveClassOfTeachers(i);
        Min2 = min(Min2, findUnfitness(i));
        fifthGenerationFixSeniorTeacherEarlyClass(i);
        if (findUnfitness(i) < Min3)
        {
            Min3 = findUnfitness(i);
            bestRoutineId = i;
        }
    }
    Print(bestRoutineId);
    dbg(Min, Min2, Min3);
    return 0;
}