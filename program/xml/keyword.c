#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

void parseStory(xmlDocPtr doc, xmlNodePtr cur){
	xmlChar *key;//xmlChar对char的基本代替，是一个UTF-8编码字符串中的一个字节
	cur = cur->xmlChildrenNode;//再次取得第一个子节点，因为文本被包含在元素的字节点中

	while(cur != NULL){//通过迭代查找我们感兴趣的keyword元素
		if((!xmlStrcmp(cur->name, (const xmlChar *)"keyword"))){//当找到keyword时，要打印它包含在xml中的记录内容
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);//取得文本的当前指针,该函数为返回的字符串分配内存，必须使用xmlFree释放
			printf("keyword:%s\n", key);
			xmlFree(key);
		}
		cur = cur->next;
	}
	return;
}

//解析文档，仅需要文件名并只调用一个函数，并有错误检查
static void parseDoc(char *docname){
	xmlDocPtr doc;//定义解析文档指针，即树的结构
	xmlNodePtr cur;//定义节点指针用于在各个节点间移动，即单个节点的结构
	doc = xmlParseFile(docname);//以默认方式读入一个UTF-8格局的文档，并返回文档指针
	if(doc == NULL){//检查解析文档是否成功
			fprintf(stderr, "Document not parsed successfully.\n");
			return;
			}
	cur = xmlDocGetRootElement(doc);//取得文档根元素
	if(cur == NULL){
		fprintf(stderr, "empty document\n");
		xmlFreeDoc(doc);
		return ;
	}

	if(xmlStrcmp(cur->name, (const xmlChar *)"story")){//检查文档的根类型是否是story
		fprintf(stderr, "document of the wrong type, root node != story");
		xmlFreeDoc(doc);
		return ;
	}

	//取得元素内容（story元素的内容）
	cur = cur->xmlChildrenNode;//取得cur的第一个字节点，cur指向文档的根，即story元素
	while(cur != NULL){
		if((!xmlStrcmp(cur->name, (const xmlChar *)"storyinfo"))){//libxml字符串比较函数，通过story的子元素查找storyinfo（包含要找的keyword元素）
			parseStory(doc, cur);//若查找成功执行此函数
		}
		cur = cur->next;
	}
	xmlFreeDoc(doc);
	return ;
}

int main(int argc, char **argv)
{
	char *docname;

	if(argc <= 1){
		printf("Usage: %s docname\n", argv[0]);
		return(0);
	}
	docname = argv[1];
	parseDoc(docname);
	return(1);
}
