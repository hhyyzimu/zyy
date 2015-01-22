//写元素
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

void parseStory(xmlDocPtr doc, xmlNodePtr cur, char *keyword)
{
	xmlNewTextChild(cur, NULL, "keyword", keyword);//添加一个当前节点的子元素到树中，一旦节点被添加，我们应当写文档到文件中，且命名空间为NULL
	return;
}

xmlDocPtr parseDoc(char *docname, char *keyword)
{
	xmlDocPtr doc;
	xmlNodePtr cur;
	
	doc = xmlParseFile(docname);
	if(doc == NULL)
	{
		fprintf(stderr, "Document not parsed successfully.\n");
		return (NULL);
	}

	cur = xmlDocGetRootElement(doc);
	if(cur == NULL){
		fprintf(stderr, "empty document\n");
		xmlFreeDoc(doc);
		return (NULL);
	}

	if(xmlStrcmp(cur->name, (const xmlChar *)"story")){
		fprintf(stderr, "document of the wrong type, root node != story");
		xmlFreeDoc(doc);
		return (NULL);
	}

	cur = cur->xmlChildrenNode;
	while(cur != NULL){
		if((!xmlStrcmp(cur->name, (const xmlChar *)"storyinfo"))){
			parseStory(doc, cur, keyword);
		}
		cur = cur->next;
	}
	return (doc);
}

int main(int argc, char **argv)
{
	char *docname;
	char *keyword;
	xmlDocPtr doc;

	if(argc <= 2){
		printf("Usage:%s docname, keyword\n", argv[0]);
		return(0);
	}

	docname = argv[1];
	keyword = argv[2];
	doc = parseDoc(docname, keyword);
	if(doc != NULL){
		xmlSaveFormatFile(docname, doc, 0);//docname为写入的文件名，此docname覆盖了原来的文件，doc是xml结构指针，1表示保证在输出上写入，0相反
		xmlFreeDoc(doc);
	}

	return (1);
}
