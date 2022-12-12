#include<iostream>
#include<regex>
#include<algorithm>
using namespace std;


string strRes[]{
	"123456asdfas123",
	"asd12adfdjaf912af",
	"afsdf1xf1",
};


string s = "Some people, when confronted with a problem, think "
    "\"I know, I'll 80hello use regular expressions.\" "
    "Now they have two problems wer123hello.";

void UseRegex();

int main()
{



	//smatch m;
	//regex pat(R"((\d{2}))");
	//regex pat1(R"(\w+\d*)");
	//string s1{ R"(\w+\d*)" };
	//regex pat2{ s1 };
	//cout << s1 << endl;
	//if (regex_match(strRes[0], m, regex("(\\d+)")))
	//{
	//	cout << "mch:\n";
	//	cout << m[0] << endl;
	//}

	//if (regex_match(strRes[0], pat))
	//{
	//	cout << "mch2:\n";
	//	cout << m[0] << endl;
	//}

	//if (regex_search(strRes[1], m, pat))
	//{
	//	cout << "search:\n";
	//	//cout << m[0] << endl;
	//	//cout << m[1] << endl;
	//	if (!m.empty())
	//	{
	//		cout << "m[1] == m[?]:" << (m[1] == "12") << endl;
	//		cout << "size: " << m.size() << endl;
	//		for (int i = 0; i < m.size(); i++)
	//		{
	//			//cout << "m[i]: " << m[i] << endl;
	//			ssub_match mats = m[i];
	//			cout << "mats: " << mats.str() << endl;
	//		}
	//	}
	//}

	UseRegex();

	return 0;
}


void UseRegex()
{
	smatch results;
	string pattern = "(\\d+hello)";
	regex r(pattern);

	cout << "found " << distance(sregex_iterator(s.begin(),s.end(),r), sregex_iterator()) <<" word\n";

	// for循环中定义了两个迭代器，it负责寻找匹配的单词，end_it是一个空迭代器，起到尾后迭代器的作用。
	for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
	{
		//cout << it->str() << endl;


		
		cout << "***************分割符****************\n";
		cout << "***************上下文****************\n";
		cout << "在此之前：" << it->prefix().str() << endl;
		cout << "在此之后：" << it->suffix().str() << endl;
		cout << "***************上下文****************\n";
		cout << "***************分割符****************\n\n";
		//cout << "匹配字符：" << it->format() << endl;
		

	}


	if (regex_search(s, results, r))
	{
		cout << results.size() << endl;
		for (int i = 0; i < results.size(); i++)
		{
			string strt(results[i].first, results[i].second);
			//string st1();
			cout <<"第"<<i<<"个：" << "first and second：" << strt << endl;
		}
	}

	// 替换所有符合的字符串
	string str2;
	// 字符串，正则，替换字符
	str2 = regex_replace(s, r, "显示");
	cout << "replace: " << str2 << endl;

}
