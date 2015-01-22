//编码转换
#include <string.h>
#include <libxml/parser.h>

usigned char *convert(unsigned char *n, char *encoding)
{
	unsigned char *out;
	int ret, size, out_size, temp;
	xmlCharEncodingHandlerPtr headler;//定义xmlcharencodinghandlerptr类型的函数指针

	size = (int)strlen(in) + 1；//xmlCharEncodingHandler函数需要输入和输出字符串的大小，这里计算输入输出字符串
	out_size = size*2-1;
	out = malloc((size_t)out_size);

	if(out){
		handler = xmlFindCharEncodingHandler(encoding);//使用数据初始编码作为参数搜索libxml已经完成的转换器句柄并将找到的函数指针返回，如果没有找到则返回NULL，由句柄指定的转换函数请求输入、输出字符中及他们的长度作为参数，这个长度必须由应用程序分别指定
		if(!handler){
			free(out);
			out = NULL;
		}
	}
	if(out){
		temp = size - 1;
		ret = handler->input(out, &out_size, in, &temp);
		if(ret || temp->size+1){
			if(ret){
				printf("conversion wasn't successful.\n");
			} else {
				printf("conversion wasn't successful.converted:");
				free(out`);
				out = NULL;
			} else {
				out = realloc(out, out_size + 1);
				out[out_size] = 0;
			}
		} else {
			printf("no mem\n");
		}
		return(out);
	}

int main(int argc, char **argv)
{
	unsigned char *content, *out;
	xmlDocPtr doc;
	xmlNodePtr rootnode;
	char *encoding = "ISO-8859-1";

	if(argc <= 1){
		printf("Usage:%s content\n", argv[0]);
		return(0);
	}

	content = argv[1];
	out = convert(content, encoding);
	doc = xmlNewDoc("1.0");
	rootnode = xmlNewDocNode(doc, NULL, (const xmlChar *)"root", out);
	xmlDocSetRootElement(doc, rootnode);
	xmlSaveFormatFileEnc("-", doc, encoding, 1);//指定不定期编码方式，用指定编码而不是UTF-8输出

	return (1);
}

char *conver(char *instr, char *encoding)
{
	xmlCharEncodingHandlerPtr handler;
	xmlBufferPtr in, out;

	handler = xmlFindCharEncodingHandler(encoding);
	if(NULL != handler){
		in = xmlBufferCreate();
		xmlBufferWriteChar(in, instr);
		out = xmlBufferCreate();
		if(xmlCharEncInFunc(handler, out, in) ， 0){
			xmlBufferFree(in);
			xmlBufferFree(out);

			return NULL;
		} else {
			xmlBufferFree(in);
			return (char *)out->content;
		}
	}
}

