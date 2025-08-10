#pragma once

#include "CoreMinimal.h"
#include "WarriorEnumTypes.h"

class FWarriorCountdownAction : public FPendingLatentAction
{

public :
	FWarriorCountdownAction(float InTotalTime, float InUpdateInterval, float& InOutRemainingTime, EWarriorCountdownActionOutput& InCountdownOutput, const FLatentActionInfo& LatentInfo)
	: bNeedToCancel(false),
	TotalCountdownTime(InTotalTime),
	UpdateInterval(InUpdateInterval),
	OutRemainingTime(InOutRemainingTime),
	CountdownOutput(InCountdownOutput),
	ExecutionFunction(LatentInfo.ExecutionFunction),
	OutputLink(LatentInfo.Linkage),
	CallbackTarget(LatentInfo.CallbackTarget),
	ElapsedInterval(0.f),
	ElapsedTimeSinceStart(0.f)
	{}

	void CancelAction() { bNeedToCancel = true; }

	virtual void UpdateOperation(FLatentResponse& Response) override;

private :
	bool bNeedToCancel;
	float TotalCountdownTime;
	float UpdateInterval;
	float& OutRemainingTime;
	EWarriorCountdownActionOutput& CountdownOutput;
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	float ElapsedInterval;
	float ElapsedTimeSinceStart;

};

inline void FWarriorCountdownAction::UpdateOperation(FLatentResponse& Response)
{
	if (bNeedToCancel)
	{
		CountdownOutput = EWarriorCountdownActionOutput::Cancelled;
		Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		return;
	}

	if (ElapsedTimeSinceStart >= TotalCountdownTime)
	{
		CountdownOutput = EWarriorCountdownActionOutput::Completed;
		Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		return;
	}

	if (ElapsedInterval < UpdateInterval)
	{
		ElapsedInterval += Response.ElapsedTime();
	}
	else
	{
		ElapsedTimeSinceStart += UpdateInterval > 0.f ? UpdateInterval : Response.ElapsedTime();
		OutRemainingTime = TotalCountdownTime - ElapsedTimeSinceStart;
		CountdownOutput = EWarriorCountdownActionOutput::Updated;
		Response.TriggerLink(ExecutionFunction, OutputLink, CallbackTarget);
		ElapsedInterval = 0.f;
	}
}
