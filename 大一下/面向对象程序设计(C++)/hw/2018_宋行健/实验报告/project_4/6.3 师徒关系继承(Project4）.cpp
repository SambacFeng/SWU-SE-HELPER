#include <iostream>
#include <vector>

using namespace std;

//基类:门派
class MenPai
{
private:
	string Men_Pai;			//储存门派名称
	vector <string> MenPai_Gongfu;		//门派的功夫有很多种，用一个动态vector去储存它
public:
	int num_MenPai_Gongfu;		//计数变量，表示此门派的第几个功夫；
	
	//默认构造函数，初始化门派名为null，门派的第一个武功为null
	MenPai()
	{
		Men_Pai = "NULL";
		MenPai_Gongfu.push_back( "NULL");
	}

	//设置门派名字
	void set_Men_Pai(string menpai)
	{
		Men_Pai = menpai;
	}

	//设置门派武功，每调用一次，vector <string> MenPai_Gongfu开辟一块内存
	void set_MenPai_Gongfu(string Gongfu)
	{
		MenPai_Gongfu[num_MenPai_Gongfu] = Gongfu;		//将传入的字符串存入前一位
		MenPai_Gongfu.push_back("");		//开辟新的内存
		num_MenPai_Gongfu++;		//计数变量加一
	}

	//对外调用私有变量的端口
	string get_Men_Pai()
	{
		return Men_Pai;
	}	
	string get_MenPai_Gongfu(int num_menpai)
	{
		return MenPai_Gongfu[num_menpai];
	}
};

//子类：师傅
class ShiFu:public MenPai
{
private:
	string Name_ShiFu;			//储存师傅名称
	vector <string> ShiFu_Gongfu;		//师傅会的功夫有很多种，用一个动态vector去储存它
public:
	int num_shifu_gongfu = 0;		//计数变量，表示这个师傅的第几个功夫；

	//默认构造函数，初始化师傅名为null，师傅的第一个武功为null
	ShiFu()
	{
		Name_ShiFu = "NULL";
		ShiFu_Gongfu.push_back( "NULL");
	}

	//设置师傅名字
	void set_Name_ShiFu(string nameshifu)
	{
		Name_ShiFu = nameshifu;
	}

	//设置师傅武功，每调用一次，vector <string> ShiFu_Gongfu开辟一块内存
	void set_ShiFu_Gongfu(string Gongfu)
	{
		ShiFu_Gongfu[num_shifu_gongfu] = Gongfu;		//将传入的字符串存入前一位
		ShiFu_Gongfu.push_back("");		//开辟新的内存
		num_shifu_gongfu++;		//计数变量加一
	}

	//对外调用私有变量的端口
	string get_Name_ShiFu()
	{
		return Name_ShiFu;
	}
	string get_ShiFu_Gongfu(int num_shifu_gongfu)
	{
		return ShiFu_Gongfu[num_shifu_gongfu];
	}

	//展示来自哪个门派
	void come_from()
	{
		cout << "门派：" << get_Men_Pai() << endl;
	}

	//展示英雄会的武功
	void GongFu(int num_menpai_gongfu)
	{
		cout << "门派的武功：" << get_MenPai_Gongfu(num_menpai_gongfu) << endl;
		cout << "自己的武功：";
		for (int j = 0; j < (int)ShiFu_Gongfu.size(); j++)
		{
			cout << get_ShiFu_Gongfu(j) << "   ";
		}
		cout << endl;
	}

	//展示英雄信息（门派、武功）
	void show(int num_menpai_gongfu)
	{
		cout << "名字：" << get_Name_ShiFu()<< endl;
		come_from();
		GongFu(num_menpai_gongfu);
		cout << endl;
	}
};

//子类：英雄
class Hero : public ShiFu
{
private:
	string Name;			//储存英雄名称
	string Gongfu_self;		//自己研究的其他武功
public:
	//默认构造函数，初始化英雄名为null，英雄的武功为null
	Hero()
	{
		Name = "NULL";
		Gongfu_self = "NULL";
	}

	//设置英雄名字
	void set_Name_self(string nameself)
	{
		Name = nameself;
	}
	//设置英雄武功
	void set_self_Gongfu(string Gongfu)
	{
		Gongfu_self = Gongfu;
	}

	//对外调用私有变量的端口
	string get_Name_self()
	{
		return Name;
	}
	string get_self_Gongfu()
	{
		return Gongfu_self;
	}

	//展示来自哪个门派和师傅
	void come_from()
	{
		cout << "门派：" << get_Men_Pai() << endl;
		cout << "师傅：" << get_Name_ShiFu() << endl;
	}

	//展示英雄会的武功
	void GongFu(int num_shifu_gongfu,int num_menpai_gongfu)
	{
		cout << "门派的武功：" << get_MenPai_Gongfu(num_menpai_gongfu) << endl;
		cout << "师傅的武功：" << get_ShiFu_Gongfu(num_shifu_gongfu) << endl;
		cout << "自己的武功：" << get_self_Gongfu() << endl;
	}

	//展示英雄信息（门派、师傅、武功）
	void show(int num_shifu_gongfu,int num_menpai_gongfu)
	{
		cout << "名字：" << get_Name_self() << endl;
		come_from();
		GongFu(num_shifu_gongfu, num_menpai_gongfu);
		cout << endl;
	}
};


int main(void)
{
	MenPai DongXie;		//门派：东邪
	MenPai XiDu;		//门派：西毒
	MenPai NanDi;		//门派：南帝
	MenPai BeiGai;		//门派：北丐

	ShiFu HongQiGong;		//师傅：洪七公
	ShiFu HuangYaoShi;		//师傅：黄药师
	ShiFu DuanZhiXing;		//师傅：段智兴
	ShiFu OuYangFeng;		//师傅：欧阳锋
	Hero GuoJing;		//英雄：郭靖
	Hero HuangRong;		//英雄：黄蓉
	Hero YangGuo;		//英雄：杨过
	Hero MeiChaoFeng;	//英雄：梅超风
	Hero MuNianCi;		//英雄：穆念慈
	Hero YangKang;		//英雄：杨康
	Hero OuYangKe;		//英雄：欧阳克

	//门派：东邪
	DongXie.set_Men_Pai("东邪");
	DongXie.set_MenPai_Gongfu("①桃花岛武功");
	DongXie.set_MenPai_Gongfu("②碧波掌法");

	//门派：西毒
	XiDu.set_Men_Pai("西毒");
	XiDu.set_MenPai_Gongfu("①瞬息千里");
	XiDu.set_MenPai_Gongfu("②神驼雪山掌");
	XiDu.set_MenPai_Gongfu("③透骨打穴法");

	//门派：南帝
	NanDi.set_Men_Pai("南帝");
	NanDi.set_MenPai_Gongfu("①一阳指");
	NanDi.set_MenPai_Gongfu("②先天功");
	
	//门派：北丐
	BeiGai.set_Men_Pai("北丐");
	BeiGai.set_MenPai_Gongfu("①打狗棒法");
	BeiGai.set_MenPai_Gongfu("②逍遥游");

	//师傅：黄药师
	HuangYaoShi.set_Name_ShiFu("黄药师");
	HuangYaoShi.set_Men_Pai(DongXie.get_Men_Pai());
	HuangYaoShi.set_MenPai_Gongfu(DongXie.get_MenPai_Gongfu(1));
	HuangYaoShi.set_ShiFu_Gongfu("①弹指神通");
	HuangYaoShi.set_ShiFu_Gongfu("②玉箫剑法");
	HuangYaoShi.set_ShiFu_Gongfu("③兰花拂穴手");
	HuangYaoShi.set_ShiFu_Gongfu("④落英神剑掌");
	HuangYaoShi.show(0);

	//师傅：欧阳锋
	OuYangFeng.set_Name_ShiFu("欧阳锋");
	OuYangFeng.set_Men_Pai(XiDu.get_Men_Pai());
	OuYangFeng.set_MenPai_Gongfu(XiDu.get_MenPai_Gongfu(0));
	OuYangFeng.set_ShiFu_Gongfu("①灵蛇拳法");
	OuYangFeng.set_ShiFu_Gongfu("②灵蛇杖法");
	OuYangFeng.set_ShiFu_Gongfu("③经脉逆行");
	OuYangFeng.show(0);

	//师傅：段智兴
	DuanZhiXing.set_Name_ShiFu("段智兴");
	DuanZhiXing.set_Men_Pai(NanDi.get_Men_Pai());
	DuanZhiXing.set_MenPai_Gongfu(NanDi.get_MenPai_Gongfu(0));
	DuanZhiXing.set_ShiFu_Gongfu("①九阴真经");
	DuanZhiXing.set_ShiFu_Gongfu("②先天功");
	DuanZhiXing.set_ShiFu_Gongfu("③一阳指");
	DuanZhiXing.show(0);

	//师傅：洪七公
	HongQiGong.set_Name_ShiFu("洪七公");
	HongQiGong.set_Men_Pai(BeiGai.get_Men_Pai());
	HongQiGong.set_MenPai_Gongfu(BeiGai.get_MenPai_Gongfu(0));
	HongQiGong.set_ShiFu_Gongfu("①降龙十八掌");
	HongQiGong.set_ShiFu_Gongfu("②打狗棒法");
	HongQiGong.set_ShiFu_Gongfu("③九阴真经");
	HongQiGong.show(0);
	
	//英雄：郭靖
	GuoJing.set_Name_self("郭靖");
	GuoJing.set_Name_ShiFu(HongQiGong.get_Name_ShiFu());
	GuoJing.set_ShiFu_Gongfu(HongQiGong.get_ShiFu_Gongfu(0));
	GuoJing.set_self_Gongfu("左右互搏");
	GuoJing.show(0, 0);

	//英雄：黄蓉
	HuangRong.set_Name_self("黄蓉");
	HuangRong.set_Men_Pai(DongXie.get_Men_Pai());
	HuangRong.set_MenPai_Gongfu(DongXie.get_MenPai_Gongfu(0));
	HuangRong.set_Name_ShiFu(HongQiGong.get_Name_ShiFu());
	HuangRong.set_ShiFu_Gongfu(HongQiGong.get_ShiFu_Gongfu(1));
	HuangRong.set_self_Gongfu("玉箫剑法");
	HuangRong.show(0, 0);

	//英雄：杨过
	YangGuo.set_Name_self("杨过");
	YangGuo.set_Name_ShiFu(HongQiGong.get_Name_ShiFu());
	YangGuo.set_ShiFu_Gongfu(HongQiGong.get_ShiFu_Gongfu(1));
	YangGuo.set_self_Gongfu("黯然销魂掌");
	YangGuo.show(0, 0);

	//英雄：梅超风
	MeiChaoFeng.set_Name_self("梅超风");
	MeiChaoFeng.set_Men_Pai(DongXie.get_Men_Pai());
	MeiChaoFeng.set_MenPai_Gongfu(DongXie.get_MenPai_Gongfu(1));
	MeiChaoFeng.set_Name_ShiFu(HuangYaoShi.get_Name_ShiFu());
	MeiChaoFeng.set_ShiFu_Gongfu(HuangYaoShi.get_ShiFu_Gongfu(1));
	MeiChaoFeng.set_self_Gongfu("九阴白骨爪");
	MeiChaoFeng.show(0, 0);

	//英雄：穆念慈
	MuNianCi.set_Name_self("穆念慈");
	MuNianCi.set_Name_ShiFu(HongQiGong.get_Name_ShiFu());
	MuNianCi.set_self_Gongfu("杨家枪法");
	MuNianCi.show(0, 0);

	//英雄：杨康
	YangKang.set_Name_self("杨康");
	YangKang.set_Name_ShiFu(OuYangFeng.get_Name_ShiFu());
	YangKang.set_ShiFu_Gongfu(OuYangFeng.get_ShiFu_Gongfu(1));
	YangKang.set_self_Gongfu("全真剑法");
	YangKang.show(0, 0);

	//英雄：欧阳克
	OuYangKe.set_Name_self("欧阳克");
	OuYangKe.set_Name_ShiFu(OuYangFeng.get_Name_ShiFu());
	OuYangKe.set_ShiFu_Gongfu(OuYangFeng.get_ShiFu_Gongfu(0));
	OuYangKe.set_self_Gongfu("神驼雪山掌");
	OuYangKe.show(0, 0);

	return 0;
}