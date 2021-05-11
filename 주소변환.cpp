#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string input, char delimiter) {
	vector<string> ret;
	stringstream ss(input);
	string temp;
	while (getline(ss, temp, delimiter)) {
		ret.push_back(temp);
	}

	return ret;
}
int main() {
	unsigned int n;
	cin >> n;
	string str;
	cin >> str;
	vector<string> result = split(str, '.');
	unsigned int answer;
	string out;
	int b1, b2, b3, b4;
	n = stoi(str);
	b1 = n / (256 * 256 * 256);
	b2 = (n - b1 * 256 * 256 * 256) / (256 * 256);
	b3 = (n - b1 * 256 * 256 * 256 - b2 * 256 * 256) / 256;
	b4 = n - b1 * 256 * 256 * 256 - b2 * 256 * 256 - b3 * 256;
	int k = 1;
	answer = 0;
	if (n == 1) {
		for (int i = 3; i >= 0; i--) {
			//cout << result[i] << " ";
			answer += stoi(result[i]) * k;
			k *= 256;
		}
		cout << answer;
	}
	else {
		out.append(to_string(b1));
		out.append(".");
		out.append(to_string(b2));
		out.append(".");
		out.append(to_string(b3));
		out.append(".");
		out.append(to_string(b4));
		cout << out;
	}

}