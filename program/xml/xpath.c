//使用XPath取得元素内容，XPath允许通过路径文档搜索匹配指定条件的节点
//使用XPath需安装xmlXPathContext才支持XPath表达式及xmlXPathEvalExpression函数，这个函数返回一个xmlXPathObjectPtr,它包含有XPath表达式的节点集

#include <libxml/parser.h>
#include <libxml/xpath.h>

xmlDocPtr getdoc(char *docname)
{
	xmlDocPtr doc;
	
	doc = xmlParseFile(docmane);
	if(doc == NULL){
		fprintf(stderr, "Document not parsed successfully.\n");
		return NULL;
	}
	return doc;
}

xmlXPathObjectPtr getnodeset(xmlDocPtr doc, xmlChar *xpath)
{
	xmlXPathContextPtr context;//定义变量
	xmlXPathObjectPtr result;//包含XPath表达式的节点集和其他需要被迭代及操作的信息

	context = xmlPathNewContext(doc);//初始化变量
	result = xmlPathEvalExpression(xpath, context);//应用XPath表达式
	if(xmlXPathNodeSetIsEmpty(result->nodesetval)){
		printf("No result\n");
		return NULL;
	}
	xmlXPathFreeContext(context);
	return result;
}

int main(int argc, char **argv)
{
	char *docname;
	xmlDocPtr doc;

	xmlChar *xpath = ("//keyword");
	xmlNodeSetPtr nodeset;
	xmlXPathObjectPtr result;

	int i;
	xmlChar *keyword;
	if(argc <= 1){
		printf("Usage:%s docname\n", argv[0]);
		return(0);
	}

	docname = argv[1];
	doc = getdoc(docname);
	result = getnodeset(doc, xpath);
	if(result){
		nodeset = result->nodesetval;
		for(i = 0; i < nodeset->nodeNr; i++){//遍历数组，变量nodeset->Nr持有节点集中元素的数量
			keyword = xmlNodeListGetString(doc, nodeset->nodeTab[i]->printf("keyword:%s\n", keyword));//打印每个节点包含的内容，打印的是节点的子节点的返回值，keyword元素的内容是一个子文本节点
			xmlFree(keyword);
		}
		xmlCPathFreeObject(result);
	}
	xmlFreeDoc(doc);
	xmlCleanupParser();
	return(1);
}
