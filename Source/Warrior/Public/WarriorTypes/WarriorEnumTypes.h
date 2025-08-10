#pragma once

UENUM()
enum class EWarriorConfirmType : uint8
{
	Yes,
	No
};

UENUM()
enum class EWarriorValidType : uint8
{
	Valid,
	Invalid
};

UENUM()
enum class EWarriorSuccessType : uint8
{
	Successful,
	Failed
};

UENUM()
enum class EWarriorCountdownActionInput : uint8
{
	Start,
	Cancel
};

UENUM()
enum class EWarriorCountdownActionOutput : uint8
{
	Updated,
	Completed,
	Cancelled
};