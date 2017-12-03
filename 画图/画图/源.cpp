/*	
	1.题中说到：画布的左下角是坐标为 (0, 0) 的位置，向右为x坐标增大的方向，向上为y坐标增大的方向。
		通过思考可知，与数组的下标比较，x方向上没有变化，y方向正好相反，即x=x;y=n-y-1;
		注意：n为数组的行数，最小值为1；y为数组的下标，最小值为0
	2.进行填充时，需要对每个元素进行递归，沿右下左上的顺序进行深度优先遍历，
		当探测到visited数组中的值为1时返回上一个元素点，换下一方向继续进行探测
	3.递归终止条件：当visited中的‘墙’内都为1时，递归终止
*/
#include<iostream>
using namespace std;

int isTrue(char **canvas, int m, int n, int x, int y,int **visited) {	//dfs真值判段
	if (x<0 || x>m || y<0 || y>=n) {
		return false;
	}
	else if (visited[y][x] == 1) {
		return false;
	}
	else {
		return true;
	}
}
int changePoint_y(int n, int y) {		//改变原点 令左下角为0,0  向上为y增
	return n - y - 1;
}
int dfs(char **canvas,int m,int n,int x,int y,char b,int **visited) {		//深度优先遍历canvas

	if (!isTrue(canvas, m, n, x, y,visited) ) {
		return 0;
	}
	else{
		canvas[y][x] = b;
		visited[y][x] = 1;
		dfs(canvas, m, n, x + 1, y, b, visited);
		dfs(canvas, m, n, x , y+1, b, visited);
		dfs(canvas, m, n, x -1, y, b, visited);
		dfs(canvas, m, n, x , y-1, b, visited);
		
	}
}
void dfs_input(char **canvas, int m, int n,int **visited) {
	int x, y;
	char b;				//(x，y)是填充的起始位置，b是填充的字母字符。
	cin >> x >> y >> b;
	y = changePoint_y(n, y);
	if (!isTrue(canvas,m,n,x,y,visited)) {
		cout << "输入坐标错误" << endl;
	}else{
			int **visited_copy = new int *[n];		//建立一个拷贝数组 防止dfs对原数组的‘墙’破坏
			for (int i = 0;i < n;i++) {
				visited_copy[i] = new int[m];
			}
			for (int i = 0;i < n;i++) {
				for (int j = 0;j < m;j++) {
					visited_copy[i][j] = visited[i][j];
				}
			}

		dfs(canvas,m,n,x,y,b,visited);

		for (int i = 0;i < n;i++) {				//还原‘墙’
			for (int j = 0;j < m;j++) {
				visited[i][j] = visited_copy[i][j];
			}
		}
	}

}
int compare(int a,int b) {//返回最小值
	return a > b ? b : a;
}

void drawline(char **canvas, int m, int n,int **visited) {			//划线
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	y1 = changePoint_y(n, y1);
	y2 = changePoint_y(n, y2);
	if (x1<0 || x1>m || y1<0 || y1>n || x2<0 || x2>m || y2<0 || y2>n || (x1 != x2 && y1 != y2)) {
		cout << "输入坐标错误" << endl;
	}
	else {
		if (x1 != x2) {				//x方向划‘-’线
			int x = compare(x1, x2);
			for (int i = 0;i < abs(x1 - x2) + 1;i++) {
				if (canvas[y1][x + i] != '|') {
					canvas[y1][x + i] = '-';
					visited[y1][x + i] = 1;
				}
				else {
					canvas[y1][x + i] = '+';
				}
			}
		}
		else if (y1 != y2) {		//y方向划‘|’线
			int y = compare(y1, y2);
			for (int i = 0;i < abs(y1 - y2) + 1;i++) {
				if (canvas[y + i][x1] != '-') {
					canvas[y + i][x1] = '|';
					visited[y + i][x1] = 1;
				}
				else {
					canvas[y + i][x1] = '+';
				}
			}
		}
	}
}

int main() {
	int m, n, p;	//n行m列
	cin >> m >> n>> p;

	if (m < 2 || n>100 || p < 0 || p>100) {
		cout << "输入信息错误" << endl;
	}
	else {
		char **canvas = new char *[n];	//动态建立字符串组canvas
		for (int i = 0;i < n;i++)
			canvas[i] = new char[m];

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				canvas[i][j] = '.';
			}
		}

		int **visited = new int *[n];		//动态建立数组visited 用来记录边界和填充过的位置
		for (int i = 0;i < n;i++) {
			visited[i] = new int[m];
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				visited[i][j] = 0;
			}
		}

		int k;	
		while (p--) {
			cin >> k;	//选择 0：划线  1：填充
			switch (k) {
			case 0:drawline(canvas, m, n,visited);break;
			case 1:dfs_input(canvas, m, n,visited);break;
			}
		}


		for (int i = 0;i < n;i++) {			//输出
			for (int j = 0;j < m;j++) {
				cout << canvas[i][j];
			}
			cout << endl;
		}
	}



		int x;
		cin >> x;
		return 0;
}