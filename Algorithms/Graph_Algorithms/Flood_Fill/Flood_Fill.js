'use strict'

class Image {
  constructor (imageAsMatrix) {
    this.matrix = imageAsMatrix
  }

  static get COLORS () {
    return {
      BLACK: 'BLACK',
      AZURE: 'AZURE',
      WHITE: 'WHITE',
      GREEN: 'GREEN'
    }
  }

  get () {
    return this.matrix
  }

  randomColor () {
    var keys = Object.keys(Image.COLORS)
    return Image.COLORS[keys[keys.length * Math.random() << 0]]
  }

  buildWhithRandomColors (rows = 5, cols = 5) {
    this.matrix = Array.from(
      { length: rows },
      () => Array.from({ length: cols }, () => this.randomColor())
    )
  }
}

class Floodfill {
  constructor (imageAsMatrix) {
    this.image = imageAsMatrix
  }

  get () {
    return this.image
  }

  bucket (row, column, newPixel) {
    const currentPixel = this.image[row][column]
    if (currentPixel === newPixel) {
      return this.image
    }
    this.fill(row, column, newPixel, currentPixel)
    return this.image
  }

  fill (row, column, newPixel, currentPixel) {
    if (
      this.rowIsLessThenZero(row) || this.columnIsLessThenZero(column) ||
      this.rowIsGreaterThenImageLength(row) || this.columnIsGreaterThenImageLength(row, column) ||
      this.currentPixelNoNeedToFill(row, column, currentPixel)
    ) {
      return
    }
    this.fillCurrentPixel(row, column, newPixel)
    this.fillPreviousRow(row, column, newPixel, currentPixel)
    this.fillNextRow(row, column, newPixel, currentPixel)
    this.fillPreviousCol(row, column, newPixel, currentPixel)
    this.fillNextCol(row, column, newPixel, currentPixel)
  }

  fillCurrentPixel (row, column, newPixel) {
    this.image[row][column] = newPixel
  }

  fillPreviousRow (row, column, newPixel, currentPixel) {
    this.fill(row - 1, column, newPixel, currentPixel)
  }

  fillNextRow (row, column, newPixel, currentPixel) {
    this.fill(row + 1, column, newPixel, currentPixel)
  }

  fillPreviousCol (row, column, newPixel, currentPixel) {
    this.fill(row, column - 1, newPixel, currentPixel)
  }

  fillNextCol (row, column, newPixel, currentPixel) {
    this.fill(row, column + 1, newPixel, currentPixel)
  }

  rowIsLessThenZero (row) {
    return (row < 0)
  }

  columnIsLessThenZero (column) {
    return (column < 0)
  }

  rowIsGreaterThenImageLength (row) {
    return row > this.image.length - 1
  }

  columnIsGreaterThenImageLength (row, column) {
    return column > this.image[row].length - 1
  }

  currentPixelNoNeedToFill (row, column, currentPixel) {
    return (this.image[row][column] !== currentPixel)
  }
}

module.exports = {
  Image,
  Floodfill
}

/** 
 * Execute for testing:
 * $ node ./Flood_Fill.js 
**/

const matrixAtBegin = [
  [Image.COLORS.AZURE, Image.COLORS.AZURE, Image.COLORS.AZURE],
  [Image.COLORS.AZURE, Image.COLORS.AZURE, Image.COLORS.GREEN],
  [Image.COLORS.AZURE, Image.COLORS.GREEN, Image.COLORS.AZURE]
]
/*
EXPECTED:
[
  [Image.COLORS.BLACK, Image.COLORS.BLACK, Image.COLORS.BLACK],
  [Image.COLORS.BLACK, Image.COLORS.BLACK, Image.COLORS.GREEN],
  [Image.COLORS.BLACK, Image.COLORS.GREEN, Image.COLORS.AZURE]
]
*/
const imageAtBegin = new Image(matrixAtBegin).get()
console.log(imageAtBegin)
const floodFill = new Floodfill(imageAtBegin)
const matrixAtEnd = floodFill.bucket(0, 1, Image.COLORS.BLACK)
console.log(new Image(matrixAtEnd).get())
