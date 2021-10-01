#!/usr/bin/env ruby

def calculateWaterArea(pillarHeights)
    waterArea = 0
    maximumHeightRight = 0
    maximumHeightLeft = 0
    tallestFromRight = Array.new(pillarHeights.length())
    tallestFromLeft = Array.new(pillarHeights.length())
    
    
    (0...tallestFromLeft.length()).each do |i|
        tallestFromLeft[i] = [maximumHeightLeft, pillarHeights[i]].max
        maximumHeightLeft = [maximumHeightLeft, pillarHeights[i]].max
    end

    (0...tallestFromRight.length()).reverse_each do |i|
        tallestFromRight[i] = maximumHeightRight
        maximumHeightRight = [maximumHeightRight, pillarHeights[i]].max
    end

    (0...pillarHeights.length()).each do |i|
        leftMax = tallestFromLeft[i]
        rightMax = tallestFromRight[i]
        minHeight = [leftMax, rightMax].min
        height = pillarHeights[i]
        if height < minHeight then
            waterArea += minHeight - height
        else
            waterArea += 0
        end
    end

    return waterArea
end

puts "Enter a list of positive numbers:"
heights = gets.chomp(" ")
            .split(" ")
            .map(&:to_i)

puts calculateWaterArea(heights)
