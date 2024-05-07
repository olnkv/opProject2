#include "func.h"
#include <gtest/gtest.h>

TEST(StudentTest, Default_Constructor)
{
    Student Student_;
    EXPECT_EQ(Student_.get_Name(), "");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}