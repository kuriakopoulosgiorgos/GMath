#include <gtest/gtest.h>
#include "Vec3.h"


TEST(Vec3, Add)
{
    Vec3<int> v1{ 1, 5, 1 };
    Vec3<int> v2{ 1, 5, 1 };
    
    Vec3<int> v3 = v1 + v2;
    
    Vec3<int> expectedVertex{ 2, 10, 2 };
    
    ASSERT_EQ(expectedVertex, v3);
}


TEST(Vec3, Substract)
{
    Vec3<int> v1{ 3, 3, 2 };
    Vec3<int> v2{ 2, 2, 1 };
    
    Vec3<int> v3 = v1 - v2;
    
    Vec3<int> expectedVertex{ 1, 1, 1 };
    
    ASSERT_EQ(expectedVertex, v3);
}


TEST(Vec3, Multiply)
{
    Vec3<int> v1{ 3, 3, 2 };
    Vec3<int> v2{ 2, 2, 1 };
    
    Vec3<int> v3 = v1 * v2;
    
    Vec3<int> expectedVertex{ 6, 6, 2 };
    
    ASSERT_EQ(expectedVertex, v3);
}


TEST(Vec3, Divide)
{
    Vec3<int> v1{ 4, 4, 2 };
    Vec3<int> v2{ 2, 2, 1 };
    
    Vec3<int> v3 = v1 / v2;
    
    Vec3<int> expectedVertex{ 2, 2, 2 };
    
    ASSERT_EQ(expectedVertex, v3);
}


TEST(Vec3, LengthSquared)
{
    Vec3F v{ 2.0f, 2.0f, 2.0f };
    
    ASSERT_FLOAT_EQ(12.f, v.LengthSquared());
}


TEST(Vec3, Length)
{
    Vec3F v{ 1.0f, 1.0f, 0.0f };
    
    ASSERT_NEAR(1.41f, v.Length(), 0.01);
}


TEST(Vec3, DotProduct)
{
    Vec3F v1{ 1.0f, 0.0f, 0.0f };
    Vec3F v2{ -1.0f, 0.0f, 0.0f };
    
    Vec3F v3{ 1.0f, 0.0f, 0.0f };
    Vec3F v4{ 1.0f, 0.0f, 0.0f };
    
    Vec3F v5{ 1.0f, 0.0f, 0.0f };
    Vec3F v6{ 0.0f, 1.0f, 0.0f };
    
    // Opposite
    ASSERT_FLOAT_EQ(-1.0f, v1.DotProduct(v2));
    // Parallel
    ASSERT_FLOAT_EQ(1.0f, v3.DotProduct(v4));
    // Perpendicular
    ASSERT_FLOAT_EQ(0.0f, v5.DotProduct(v6));
}


TEST(Vec3, NormalizeTest)
{
    Vec3F v{ 1.0f, 1.0f, 0.0f };
    v.Normalize();
    
    ASSERT_NEAR(0.707, v.x, 0.001f);
    ASSERT_NEAR(0.707, v.y, 0.001f);
    ASSERT_FLOAT_EQ(1.0f, v.Length());
}


TEST(Vec3, GetNormalzedTest)
{
    Vec3F v{ 1.0f, 1.0f, 0.0f };
    Vec3F normalized = v.GetNormalized();
    
    ASSERT_NEAR(0.707f, normalized.x, 0.001f);
    ASSERT_NEAR(0.707f, normalized.y, 0.001f);
    ASSERT_FLOAT_EQ(normalized.Length(), 1.0f);
}