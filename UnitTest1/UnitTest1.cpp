#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.4(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(ArrayTests)
    {
    public:

        // ���� ��� countNegativeElements
        TEST_METHOD(TestCountNegativeElements)
        {
            const int n = 5;
            double arr[n] = { -1.0, 2.0, -3.5, 4.0, -2.0 };
            int expectedCount = 3; // ���� ��� �䒺���� ��������

            // ��������� ������� countNegativeElements
            int actualCount = countNegativeElements(arr, n);

            // �������� ����������
            Assert::AreEqual(expectedCount, actualCount);
        }

    };
}
