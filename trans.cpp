#include<bits/stdc++.h>
using namespace std;
int system(string str)
{
	return system(str.c_str());
}
void moveFile(string fromPath,string toPath)
{
	cout<<fromPath<<" => "<<toPath<<endl;
	system("cp "+fromPath+" "+toPath);
}
string toString(int x)
{
	stringstream ss;
	ss.clear();
	ss<<x;
	string str;
	ss>>str;
	return str;
}
vector<string> listFiles(string folderPath)
{
	system("ls "+folderPath+" > ./tmp.txt");
	vector<string> fileList;
	fileList.clear();
	fstream list("./tmp.txt",ios::in);
	string fileName;
	while(list>>fileName)
		fileList.push_back(fileName);
	return fileList;
}
void transferFolder(string folderPath,string outputPath,string fileSuffix)
{
	vector<string> fileList=listFiles(folderPath);
	for(int i=0;i<fileList.size();i++)
	{
		moveFile(folderPath+"/"+fileList[i],outputPath+"/data"+toString(i)+"."+fileSuffix);
	}
}
int main()
{
	system("mkdir ./data");
	transferFolder("./in","./data","in");
	transferFolder("./out","./data","out");
	system("rm ./tmp.txt");
}