/**
@author		Shun Moriya
@copyright	2024- Shun Moriya
All Rights Reserved.

https://www.youtube.com/channel/UCkLXe57GpUyaOoj2ycREU1Q
*/

#pragma once
#include <Kismet/BlueprintFunctionLibrary.h>
#include "DrawLots.generated.h"

/*
Probability of Winning and Lottery Items

当選確率と抽選アイテム
*/
USTRUCT(BlueprintType)
struct DRAWLOTS_API FLotteryItem
{
	GENERATED_BODY()

	/*
	Lottery probability
	
	抽選確率
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DrawLots", meta = (ClampMin = "1"))
	uint8 Odds = 1;

	/*
	Winning item

	当選アイテム
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DrawLots")
	TObjectPtr<UObject> Item;

	FLotteryItem()
		: Odds(1)
		, Item(nullptr)
	{}

	FLotteryItem(const uint8 odds, UObject* item) noexcept
		: Odds(odds)
		, Item(item)
	{}
};

/*
Lottery data for which the probability of winning can be specified
Add the FLotteryItem you want to draw to LotteryItems and call the DrawLotsObject function to draw the lots.

当選確率が指定可能な抽選データ
LotteryItemsに抽選したいFLotteryItemを追加してDrawLotsObject関数を呼ぶと抽選します
*/
USTRUCT(BlueprintType)
struct DRAWLOTS_API FDrawLotsObject
{
	GENERATED_BODY()

	/*
	Probability of Winning and Lottery Items

	当選確率と抽選アイテム
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DrawLots")
	TArray<FLotteryItem> LotteryItems;

	/*
	Drawing lots

	抽選します
	*/
	UObject* Draw(const bool consecutive) const;

private:
	mutable int32 mLastLotteryNumber = -1;
};

/*
Drawing data for which the probability of winning can be specified
Define probabilities in Odds and call DrawLotsIndex function to draw lots.

当選確率が指定可能な抽選データ
Oddsに確率を定義してDrawLotsIndex関数を呼ぶと抽選します
*/
USTRUCT(BlueprintType)
struct DRAWLOTS_API FDrawLotsIndex
{
	GENERATED_BODY()

	/*
	Probability (enter a value greater than or equal to 1)
	
	確率（１以上の値を入力してください）
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DrawLots")
	TArray<uint8> Odds;

	/*
	Drawing lots

	抽選します
	*/
	int32 Draw(const bool consecutive) const;

private:
	mutable int32 mLastLotteryNumber = -1;
};

/*
Probability-specific draw functions

確率指定可能な抽選関数
*/
UCLASS(Blueprintable)
class DRAWLOTS_API UDrawLotsBlueprint : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*
	Drawing with specifiable probability of winning.
	Returns the winning item.
	Returns nullptr if the item cannot be drawn, e.g. if the probability is set to all 0's. If "consecutive" is disabled, the same item will not be drawn consecutively.
	If you disable the "directive", the same item will not be drawn consecutively.

	当選確率が指定可能な抽選
	当選したアイテムを返します。
	確率をすべて０にした場合など抽選できない場合はnullptrを返します。
	consecutiveを無効にすると同じアイテムが連続で当選しません
	*/
	UFUNCTION(BlueprintCallable, Category = "DrawLots")
	static UObject* DrawLotsObject(const FDrawLotsObject& drawLotsObject, const bool consecutive = true)
	{
		return drawLotsObject.Draw(consecutive);
	}

	/*
	Draws a lottery with specifiable probability of winning.
	Returns the winning sequence number.
	Returns -1 if the lottery cannot be performed, e.g. if all probabilities are set to 0.
	If you disable the "sequence" option, the same sequence number will not be drawn consecutively.

	当選確率が指定可能な抽選をします
	当選した配列番号を返します。
	確率をすべて０にした場合など抽選できない場合は-1を返します。
	consecutiveを無効にすると同じ番号が連続で当選しません
	*/
	UFUNCTION(BlueprintCallable, Category = "DrawLots")
	static int32 DrawLotsIndex(const FDrawLotsIndex& drawLotsIndex, const bool consecutive = true)
	{
		return drawLotsIndex.Draw(consecutive);
	}
};
