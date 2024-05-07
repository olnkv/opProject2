#include "func.h"
#include <gtest/gtest.h>

TEST(StudentTest, Default_Constructor)
{
    Student Student_;
    EXPECT_EQ(Student_.get_Name(), "");
    EXPECT_EQ(Student_.get_Surname(), "");
    EXPECT_EQ(Student_.hwRes_Empty(), true);
    EXPECT_EQ(Student_.hwRes_Size(), 0);
    EXPECT_EQ(Student_.get_exRes(), 0);
    EXPECT_EQ(Student_.get_Avg(), 0.0);
    EXPECT_EQ(Student_.get_Med(), 0.0);
}

TEST(StudentTest, Param_Constructor)
{
    Student Student_("Edvin", "Olenkovic");
    EXPECT_EQ(Student_.get_Name(), "Edvin");
    EXPECT_EQ(Student_.get_Surname(), "Olenkovic");
    EXPECT_EQ(Student_.hwRes_Empty(), true);
    EXPECT_EQ(Student_.hwRes_Size(), 0);
    EXPECT_EQ(Student_.get_exRes(), 0);
    EXPECT_EQ(Student_.get_Avg(), 0.0);
    EXPECT_EQ(Student_.get_Med(), 0.0);
}

TEST(StudentTest, Copy_Constructor)
{
    Student Student_("Edvin", "Olenkovic");
    EXPECT_EQ(Student_.get_Name(), "Edvin");
    EXPECT_EQ(Student_.get_Surname(), "Olenkovic");
    Student Student0(Student_);
    EXPECT_EQ(Student0.get_Name(), "Edvin");
    EXPECT_EQ(Student0.get_Surname(), "Olenkovic");
}

TEST(StudentTest, Copy_Operator)
{
    Student Student_("Edvin", "Olenkovic");
    EXPECT_EQ(Student_.get_Name(), "Edvin");
    EXPECT_EQ(Student_.get_Surname(), "Olenkovic");
    Student Student0 = Student_;
    EXPECT_EQ(Student0.get_Name(), "Edvin");
    EXPECT_EQ(Student0.get_Surname(), "Olenkovic");
}

TEST(StudentTest, Move_Operator)
{
    Student Student_("Edvin", "Olenkovic");
    EXPECT_EQ(Student_.get_Name(), "Edvin");
    EXPECT_EQ(Student_.get_Surname(), "Olenkovic");
    Student Student0 = std::move(Student_);
    EXPECT_EQ(Student0.get_Name(), "Edvin");
    EXPECT_EQ(Student0.get_Surname(), "Olenkovic");
}

TEST(StudentTest, Get_Set)
{
    Student Student_;
    Student_.set_Name("Edvin");
    EXPECT_EQ(Student_.get_Name(), "Edvin");
    Student_.set_Surname("Olenkovic");
    EXPECT_EQ(Student_.get_Surname(), "Olenkovic");
    Student_.set_Hw(10);
    EXPECT_EQ(Student_.hwRes_Size(), 1);
    Student_.set_Avg(9.5);
    EXPECT_EQ(Student_.get_Avg(), 9.5);
    Student_.clear_All();
    EXPECT_EQ(Student_.get_Name(), "");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}