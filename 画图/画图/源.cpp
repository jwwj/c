/*	
	1.����˵�������������½�������Ϊ (0, 0) ��λ�ã�����Ϊx��������ķ�������Ϊy��������ķ���
		ͨ��˼����֪����������±�Ƚϣ�x������û�б仯��y���������෴����x=x;y=n-y-1;
		ע�⣺nΪ�������������СֵΪ1��yΪ������±꣬��СֵΪ0
	2.�������ʱ����Ҫ��ÿ��Ԫ�ؽ��еݹ飬���������ϵ�˳�����������ȱ�����
		��̽�⵽visited�����е�ֵΪ1ʱ������һ��Ԫ�ص㣬����һ�����������̽��
	3.�ݹ���ֹ��������visited�еġ�ǽ���ڶ�Ϊ1ʱ���ݹ���ֹ
*/
#include<iostream>
using namespace std;

int isTrue(char **canvas, int m, int n, int x, int y,int **visited) {	//dfs��ֵ�ж�
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
int changePoint_y(int n, int y) {		//�ı�ԭ�� �����½�Ϊ0,0  ����Ϊy��
	return n - y - 1;
}
int dfs(char **canvas,int m,int n,int x,int y,char b,int **visited) {		//������ȱ���canvas

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
	char b;				//(x��y)��������ʼλ�ã�b��������ĸ�ַ���
	cin >> x >> y >> b;
	y = changePoint_y(n, y);
	if (!isTrue(canvas,m,n,x,y,visited)) {
		cout << "�����������" << endl;
	}else{
			int **visited_copy = new int *[n];		//����һ���������� ��ֹdfs��ԭ����ġ�ǽ���ƻ�
			for (int i = 0;i < n;i++) {
				visited_copy[i] = new int[m];
			}
			for (int i = 0;i < n;i++) {
				for (int j = 0;j < m;j++) {
					visited_copy[i][j] = visited[i][j];
				}
			}

		dfs(canvas,m,n,x,y,b,visited);

		for (int i = 0;i < n;i++) {				//��ԭ��ǽ��
			for (int j = 0;j < m;j++) {
				visited[i][j] = visited_copy[i][j];
			}
		}
	}

}
int compare(int a,int b) {//������Сֵ
	return a > b ? b : a;
}

void drawline(char **canvas, int m, int n,int **visited) {			//����
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	y1 = changePoint_y(n, y1);
	y2 = changePoint_y(n, y2);
	if (x1<0 || x1>m || y1<0 || y1>n || x2<0 || x2>m || y2<0 || y2>n || (x1 != x2 && y1 != y2)) {
		cout << "�����������" << endl;
	}
	else {
		if (x1 != x2) {				//x���򻮡�-����
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
		else if (y1 != y2) {		//y���򻮡�|����
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
	int m, n, p;	//n��m��
	cin >> m >> n>> p;

	if (m < 2 || n>100 || p < 0 || p>100) {
		cout << "������Ϣ����" << endl;
	}
	else {
		char **canvas = new char *[n];	//��̬�����ַ�����canvas
		for (int i = 0;i < n;i++)
			canvas[i] = new char[m];

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				canvas[i][j] = '.';
			}
		}

		int **visited = new int *[n];		//��̬��������visited ������¼�߽��������λ��
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
			cin >> k;	//ѡ�� 0������  1�����
			switch (k) {
			case 0:drawline(canvas, m, n,visited);break;
			case 1:dfs_input(canvas, m, n,visited);break;
			}
		}


		for (int i = 0;i < n;i++) {			//���
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