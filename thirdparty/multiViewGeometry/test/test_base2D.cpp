#include <gtest/gtest.h>
#include "base2D.h"

TEST(MyclassTest,PrintMessage){
    Myclass myclass("test_name");
    EXPECT_NO_THROW(myclass.PrintMessage());
}

TEST(MyclassTest,SetFlag){
    Myclass myclass("test_flag");
    EXPECT_NO_THROW(myclass.SetFlag("NEW NAME"));

}

int main(int argc, char ** argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}