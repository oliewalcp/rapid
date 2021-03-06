#include "TreeTool.h"

#pragma GCC diagnostic ignored  "-Wwrite-strings"
#ifdef QT_LIB
namespace rapid
{
static int argc = 1;
static char *argv[1] = {"rapid.exe"};
QApplication app(argc, argv);

void test_TreeTool_main()
{
    auto get_data_func = [](const BTreeNode<RBDataNode<int>> *node) -> std::string {
        if(node == nullptr) return "";
        return std::to_string(node->data().data());
    };
    auto get_color_func = [](const BTreeNode<RBDataNode<int>> *node) -> unsigned long {
        return static_cast<unsigned long>(node->data().color());
    };
    MainWindow<RBDataNode<int>, RedBlackTree<int>> mw1(RedBlackTree<int>().to_ordinary_tree(), get_data_func, get_color_func);
    mw1.setWindowTitle("test");
    mw1.show();

    app.exec();
}

}

#endif
