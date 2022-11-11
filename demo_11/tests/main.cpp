#include <QCoreApplication>
#include <QTimer>
#include <gtest/gtest.h>
#include <sanitizer/asan_interface.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);

    int ret = RUN_ALL_TESTS();

    return ret;  // app.exec();
}
