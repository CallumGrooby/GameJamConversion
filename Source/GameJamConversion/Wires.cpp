// Fill out your copyright notice in the Description page of Project Settings.


#include "Wires.h"
#include "Algo/Reverse.h"

const int maxIterations = 100;
/*
void AWires::Solve(FVector points[], FVector target)
{
	FVector orgin = points[0];

	float segmentLengths[] = points->Size();
	for (int i = 0; i < points->Size(); i++)
	{
		FVector tmp = points[i + 1] - points[i];
		segmentLengths[i] = getMagnitude(tmp);
	}

	for (int interations = 0; interations < maxIterations; interations++)
	{
		bool startingFromTarget = interations % 2 == 0;
		Algo::Reverse(points);
		Algo::Reverse(segmentLengths);
		points[0] = (startingFromTarget) ? target : orgin;

		for (size_t i = 0; i < points->Size(); i++)
		{
			FVector dirUnNormal = {points[i] - points[i - 1]};
			FVector dir = dirUnNormal.Normalize();

		}
	}
}

FVector getMagnitude(FVector v1)
{
	FVector vectorsMagnitude = { v1.X * v1.X, v1.Y * v1.Y,v1.Z * v1.Z };

		return vectorsMagnitude;
}
*/