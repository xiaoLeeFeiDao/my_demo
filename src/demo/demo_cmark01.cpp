#include <cmark.h>
#include <iostream>
#include <string>
#include "demo_inner.h"
// 封装一个简单的Markdown到HTML的转换函数
std::string markdown_to_html(const std::string &markdown) {
  // 将Markdown转换为HTML
  char *html = cmark_markdown_to_html(markdown.c_str(), markdown.length(),
                                      CMARK_OPT_DEFAULT);

  std::string result(html);
  free(html);
  return result;
}

void demo_cmark01() {
  std::string markdown =
      "# Hello, World!\n\nThis is a simple Markdown document.\n\n## Lists\n\n- "
      "Item 1\n- Item 2\n- Item 3\n\n## Code\n\n```c\nint main() {\n    "
      "printf(\"Hello, World!\");\n    return 0;\n}\n```\n\n## Tables\n\n| "
      "Column 1 | Column 2 | Column 3 |\n| -------- | -------- | -------- |\n| "
      "Item 1   | Item 2   | Item 3   |\n| Item 4   | Item 5   | Item 6   "
      "|\n\n## Links\n\n[Google](https://www.google.com)\n\n## "
      "Images\n\n![Google "
      "Logo](https://www.google.com/images/branding/googlelogo/2x/"
      "googlelogo_color_272x92dp.png)\n\n## Blockquotes\n\n> This is a "
      "blockquote.\n\n## Horizontal Rules\n\n---\n\n## Emphasis\n\n*This text "
      "will be italic*\n_This will also be italic_\n\n**This text will be "
      "bold**\n__This will also be bold__\n\n_You **can** combine them_";
  std::string html = markdown_to_html(markdown);

  std::cout << "Original Markdown:\n";
  std::cout << "-----------------\n";
  std::cout << markdown << "\n\n";

  std::cout << "Generated HTML:\n";
  std::cout << "--------------\n";
  std::cout << html << std::endl;

  return;
}
