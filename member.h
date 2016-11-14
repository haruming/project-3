class person {
public:
	static next_id;
	person(string para_name);		//负责初始化name和id，并将next_id++
	void changeName(string para_name);
	int getId();
private:
	string name;
	int id;
}

//妻子储存在丈夫的vector里，儿子储存在母亲的vector里，女儿不储存
class male:public person {
public:
	male(string para_name);			//注意要调用person的构造函数
	male(const male& another);		//id相同
	male& operator=(const male& another);		//id相同
	std::vector<female> getWives();	//注意返回的是副本而不是引用
	bool divorce();					//如果还没有妻子或已经离婚，则什么也不做，返回false
	bool marry(string wife_name);	//如果已经有妻子，则什么也不做，返回false
	bool addSon(string son_name);	//如果还没有妻子或已经离婚，则什么也不做，返回false
									//调用现任妻子的addSon
	bool deleteSon(int id);			//没有这个儿子则返回false

private:
	std::vector<female> wives;
}


class female:public person {
public:
	female(string para_name);
	female(const female& another);
	female& operator=(const female& another);
	std::vector<male> getSons();
	void addSon(string son_name);
	bool is_ex_wife();				//直接返回have_divorce
private:
	std::vector<male> sons;
	bool have_divorce;
}