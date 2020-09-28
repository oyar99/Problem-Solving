#include <iostream>
#include <string>


struct Path {
	std::string path;
	int points;

	Path(std::string path) : path(path), points(0){}

	void add_points(char p) {
		if (p == 'E')
			points += 1;
		else
			points += 2;
	}
} typedef;

std::string get_path(Path other, int n) {

	Path my_path = Path("");
	bool cross = true;
	bool going_south = false;
	int s = 0, e = 0;

	for (int i = 0; i < 2 * n - 2; ++i) {

		char dir;

		if (other.points == my_path.points) {
			cross = true;
		}
	
		if (cross) {
			if (other.path[i] == 'E') {
				if (s < n - 1) {
					dir = 'S';
					going_south = true;
				}
				else {
					return "ERROR";
				}
			}
			else {
				if (e < n - 1) {
					dir = 'E';
					going_south = false;
				}
				else {
					return "ERROR";
				}
			}
			cross = false;
		}
		else {
			int random = rand() % 2 + 1;
			if (random == 1) {
				if (e < n - 1) {
					dir = 'E';
					going_south = false;
				}
				else if (s < n -1){
					dir = 'S';
					going_south = true;
				}
				else {
					return "ERROR";
				}
			}
			else {
				if (s < n - 1) {
					dir = 'S';
					going_south = true;
				}
				else if (e < n -1){
					dir = 'E';
					going_south = false;
				}
				else {
					return "ERROR";
				}
			}
		}

		if (dir == 'S') {
			s++;
		}
		else {
			e++;
		}
		my_path.path += dir;
		other.add_points(other.path[i]);
		my_path.add_points(dir);
	}
	return my_path.path;
}

int main() {
    int T;
    std::cin >> T;
    int t = 1;
    while (T != 0) {
        T--;
        int n;
        std::cin >> n;
        std::string p;
        std::cin >> p;
        
        Path path = Path(p);
		std::string sol;

		while (true) { 
			sol = get_path(path, n);

			if (sol != "ERROR" && sol != "")
				break;
		}
        
        std::cout << "Case #" << t++ << ": " << sol << std::endl;
    }
    return 0;
}