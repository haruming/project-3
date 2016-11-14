class UI {
public:
	UI(string root_name);
private:
	void getOperation();
	void marry();
	void addSon();
	void deleteSon();
	void divorce();
	void print();

	person& getMaleById(int id);

	male root;
}