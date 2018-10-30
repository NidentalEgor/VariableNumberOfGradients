#include "gtest/gtest.h"
#include "Tests.h"

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	// ::testing::GTEST_FLAG(filter) = "DataStorageComplexTest.CheckVisitsByUserIdAfterVisitUpdateTest";
	// ::testing::GTEST_FLAGetVisitsAmountG(filter) = "DataStorageComplexTest.CheckAverageLocationAfterVisitUpdateTest";
//	::testing::GTEST_FLAG(filter) = "SerializeLocationTest.NoDataTest";
		// ::testing::GTEST_FLAG(filter) = "SerializeLocationTest.Rename";
//		::testing::GTEST_FLAG(filter) = "SerializeLocationTest.NoDataTest";
	return RUN_ALL_TESTS();
}