/**
@author		Shun Moriya
@copyright	2024- Shun Moriya
All Rights Reserved.

https://www.youtube.com/channel/UCkLXe57GpUyaOoj2ycREU1Q
*/

#include "DrawLots.h"
#include <GenericPlatform/GenericPlatformMath.h>

UObject* FDrawLotsObject::Draw(const bool consecutive) const
{
	TArray<FLotteryItem> items;
	items.Reserve(LotteryItems.Num());

	int32 totalWeight = 0;
	for (int32 i = 0; i < LotteryItems.Num(); ++i)
	{
		if (consecutive || i != mLastLotteryNumber)
		{
			const auto& lotteryItem = LotteryItems[i];
			totalWeight += lotteryItem.Odds;
			items.Emplace(totalWeight, lotteryItem.Item);
		}
	}

	if (totalWeight <= 0)
		return nullptr;

	// MEMO: specify random numbers externally.
	const int32 rnd = FGenericPlatformMath::Rand() % totalWeight;
	for (int32 i = 0; i < items.Num(); ++i)
	{
		const auto& item = items[i];
		if (rnd < item.Odds)
		{
			mLastLotteryNumber = i;
			return item.Item;
		}
	}

	return nullptr;
}

int32 FDrawLotsIndex::Draw(const bool consecutive) const
{
	TArray<int32> items;
	items.Reserve(Odds.Num());

	int32 totalWeight = 0;
	for (int32 i = 0; i < Odds.Num(); ++i)
	{
		if (consecutive || i != mLastLotteryNumber)
		{
			totalWeight += Odds[i];
			items.Add(totalWeight);
		}
	}

	if (totalWeight <= 0)
		return -1;

	// MEMO: specify random numbers externally.
	const int32 rnd = FGenericPlatformMath::Rand() % totalWeight;
	for (int32 i = 0; i < items.Num(); ++i)
	{
		if (rnd < items[i])
		{
			mLastLotteryNumber = i;
			return i;
		}
	}

	return -1;
}
