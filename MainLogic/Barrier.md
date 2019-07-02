# Barrier类
基类：Barrier  
派生类：CircleBarrier、RectangleBarrier、TriangleBarrier、PentagonBarrier、HexagonBarrier
## 属性与方法
### Barrier类
#### 属性
private属性：  
double x;  
double y;  
int hp;  
double calculate_radius;  

其中，x与y代表障碍物质心的坐标，hp代表障碍物的生命值(即需要几次碰撞消除)，calculate_radius代表外接圆半径。  
#### 方法
Barrier(double set_x, double set_y, int hp = 1);  
virtual ~Barrier();  

inline double GetX();  
inline double GetY();  
inline int GetHp();  
inline double GetCalculateRadius();  

inline void SetX(double set_x);  
inline void SetY(double set_y);  
inline void Damaged(int damage = 1);  
inline void SetHp(int set_hp);  

virtual void SetCalculateRadius(double r);  
bool IsCovered(const Barrier &br);  

Barrier(double set_x, double set_y, int hp = 1);  
Barrier类的构造函数，参数依次为设定的X坐标值、Y坐标值、生命值，其中生命值默认为1。

virtual ~Barrier();  
析构函数

下面的Get和Set等函数分别为4个获取X，Y，生命值，外接圆半径的函数以及4个设定相应值的函数。
Damaged函数代表减少对应的生命值函数，默认减少1。  

IsCovered的返回值是是否两个障碍物有重叠。

### CircleBarrier类
#### 属性
double radius;  

圆的半径

#### 方法
CircleBarrier(double x, double y, double r, int hp = 1);
virtual ~CircleBarrier();

inline double GetRadius();

inline void SetRadius(double r);  
virtual void SetCalculateRadius(double r);  

CircleBarrier(double x, double y, double r, int hp = 1);  
构造函数，参数依次为XY坐标，半径，生命值，生命值默认为1。

~CircleBarrier();  
析构函数

Get和Set函数是获取/设定相应的值

### RectangleBarrier类
#### 属性
double length;  
double width;  
double rotation;  

其中，length和width代表矩形的长与宽，rotation代表旋转角度。旋转角以矩形长边与坐标X轴平行为0。

#### 方法

RectangleBarrier(double x, double y, double len, double wid, int hp = 1, double rot = 0.0);
virtual ~RectangleBarrier();

inline double GetLength();  
inline double GetWidth();  
inline double GetRot();  

inline void SetLength(double length);  
inline void SetWidth(double width);  
inline void SetRot(double rotation);  

virtual void SetCalculateRadius(double r);  
virtual void GetPos(double points[]);

RectangleBarrier(double x, double y, double len, double wid, int hp = 1, double rot = 0.0);  
参数依次是XY坐标、长、宽、生命值、旋转角。生命值和旋转角的默认值分别为1和0。

~RectangleBarrier();  
析构函数

以下的Get和Set是设定和获取相应属性值的函数。  
其中GetPos函数是获取各个顶点坐标的函数。  
void GetPos(double points[]);  
参数为数组，各个点的坐标将以逆时针顺序从第一象限点开始，分别按X和Y的顺序赋值到points数组中。

###  Triangle类
#### 属性
double length;  
double rotation;

其中，length是三角形的边长，rotation是旋转角。

#### 方法
TriangleBarrier(double x, double y, double len, int hp = 1, double rot = 0.0);  
virtual ~TriangleBarrier();

inline double GetLength();  
inline double GetRot();  

inline void SetLength(double length);  
inline void SetRot(double rotation);  

virtual void SetCalculateRadius(double r);  
virtual void GetPos(double points[]);

TriangleBarrier(double x, double y, double len, int hp = 1, double rot = 0.0);  
构造函数，参数依次为XY坐标、边长、生命值、旋转角。生命值和旋转角默认值为1和0。

virtual ~TriangleBarrier();  
析构函数

以下Get和Set方法与Rectangle类一致，不再赘述。

### PentagonBarrier类
#### 属性
double radius;  
double rotation;  

其中，radius代表质心到顶点的距离，为方便称其为半径。rotation是旋转角。

#### 方法

PentangoBarrier(double x, double y, double r, int hp = 1, double rot = 0.0);  
virtual ~PentangoBarrier();

inline double GetRadius() { return this->radius; }  
inline double GetRot() { return this->rotation; }

inline void SetLength(double radius) { this->radius = radius; }  
inline void SetRot(double rotation) { this->rotation = rotation; }
	
virtual void SetCalculateRadius(double r) { Barrier::SetCalculateRadius(r); }  
virtual void GetPos(double points[]);

PentagonBarrier(double x, double y, double r, int hp = 1, double rot = 0.0);  
构造函数，参数依次为XY坐标、半径、生命值，旋转角。生命值和旋转角的默认值为1和0。

~PentagonBarrier();  
析构函数

Get和Set方法与Rectangle类一致，不再赘述。

### HexagonalBarrier类
与PentagonBarrier类一致，不再赘述。