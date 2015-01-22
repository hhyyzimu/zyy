//写属性，类似于给一个新元素写文本
//此代码将添加一个reference节点URI属性到文档中，reference是story元素的一个子节点
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

xmlDocPtr parseDoc(char *docname, char *uri)
{
	xmlDocPtr doc;
	xmlNodePtr cur;
	xmlNodePtr newnode;
	xmlAttrPtr newattr;

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
	newnode = xmlNewTextChild(cur, NULL, "reference", NULL);//添加一个新节点到当前节点位置
	newattr = xmlNewProp(newnode, "uri", uri);//添加节点后，将添加的元素及文本内容写入到磁盘

	return(doc);
}

int main(int argc, char **argv)
{
	char *docname;
	char *uri;
	xmlDocPtr doc;

	if(argc <= 2){
		printf("Usage:%s docname, uri\n", argv[0]);
		return(0);
	}

	docname = argv[1];
	uri = argv[2];
	doc = parseDoc(docname, uri);
	if(doc != NULL){
		xmlSaveFormatFile(docname, doc, 1);
		xmlFreeDoc(doc);
	}
	return (1);
}
