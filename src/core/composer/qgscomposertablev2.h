/***************************************************************************
                         qgscomposertablev2.h
                         ------------------
    begin                : July 2014
    copyright            : (C) 2014 by Nyall Dawson, Marco Hugentobler
    email                : nyall dot dawson at gmail dot com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSCOMPOSERTABLEV2_H
#define QGSCOMPOSERTABLEV2_H

#include "qgscomposermultiframe.h"
#include <QFont>
#include <QColor>
#include <QPair>

class QgsComposerTableColumn;

/**List of QVariants, representing a the contents of a single row in
 * a QgsComposerTable
 * \note Added in version 2.5
*/
typedef QList< QVariant > QgsComposerTableRow;

/**List of QgsComposerTableRows, representing rows and column cell contents
 * for a QgsComposerTable
 * \note Added in version 2.5
*/
typedef QList< QgsComposerTableRow > QgsComposerTableContents;

/**List of column definitions for a QgsComposerTable
 * \note Added in version 2.5
*/
typedef QList<QgsComposerTableColumn*> QgsComposerTableColumns;

/**A class to display feature attributes in the print composer, and allow
 * the table to span over multiple frames
 * @note added in QGIS 2.5
 */
class CORE_EXPORT QgsComposerTableV2: public QgsComposerMultiFrame
{
    Q_OBJECT

  public:

    /*! Controls how headers are horizontally aligned in a table
     */
    enum HeaderHAlignment
    {
      FollowColumn, /*!< header uses the same alignment as the column */
      HeaderLeft, /*!< align headers left */
      HeaderCenter, /*!< align headers to center */
      HeaderRight /*!< align headers right */
    };

    /*! Controls where headers are shown in the table
     */
    enum HeaderMode
    {
      FirstFrame = 0, /*!< header shown on first frame only */
      AllFrames, /*!< headers shown on all frames */
      NoHeaders /*!< no headers shown for table */
    };

    QgsComposerTableV2( QgsComposition* composition, bool createUndoCommands );
    QgsComposerTableV2();

    virtual ~QgsComposerTableV2();

    virtual bool writeXML( QDomElement& elem, QDomDocument & doc, bool ignoreFrames = false ) const;

    virtual bool readXML( const QDomElement& itemElem, const QDomDocument& doc, bool ignoreFrames = false );

    virtual QSizeF totalSize() const;

    virtual void render( QPainter* p, const QRectF& renderExtent, const int frameIndex );


    /**Sets the margin distance between cell borders and their contents.
     * @param margin margin for cell contents
     * @see cellMargin
     */
    void setCellMargin( const double margin );

    /**Returns the margin distance between cell borders and their contents.
     * @returns margin for cell contents
     * @see setCellMargin
     */
    double cellMargin() const { return mCellMargin; }

    /**Sets the font used to draw header text in the table.
     * @param font font for header cells
     * @see headerFont
     * @see setContentFont
     */
    void setHeaderFont( const QFont& font );

    /**Returns the font used to draw header text in the table.
     * @returns font for header cells
     * @see setHeaderFont
     * @see contentFont
     */
    QFont headerFont() const { return mHeaderFont; }

    /**Sets the color used to draw header text in the table.
     * @param color header text color
     * @see headerFontColor
     * @see setHeaderFont
     * @see setContentFontColor
     */
    void setHeaderFontColor( const QColor& color );

    /**Returns the color used to draw header text in the table.
     * @returns color for header text
     * @see setHeaderFontColor
     * @see headerFont
     * @see contentFontColor
     */
    QColor headerFontColor() const { return mHeaderFontColor; }

    /**Sets the horizontal alignment for table headers
     * @param alignment Horizontal alignment for table header cells
     * @see headerHAlignment
     */
    void setHeaderHAlignment( const HeaderHAlignment alignment );

    /**Returns the horizontal alignment for table headers
     * @returns Horizontal alignment for table header cells
     * @see setHeaderHAlignment
     */
    HeaderHAlignment headerHAlignment() const { return mHeaderHAlignment; }

    /**Sets the display mode for headers in the table. This property controls
     * if and where headers are shown in the table.
     * @param mode display mode for headers
     * @see headerMode
     */
    void setHeaderMode( const HeaderMode mode );

    /**Returns the display mode for headers in the table. This property controls
     * if and where headers are shown in the table.
     * @returns display mode for headers
     * @see setHeaderMode
     */
    HeaderMode headerMode() const { return mHeaderMode; }

    /**Sets the font used to draw text in table body cells.
     * @param font font for table cells
     * @see contentFont
     * @see setHeaderFont
     */
    void setContentFont( const QFont& font );

    /**Returns the font used to draw text in table body cells.
     * @returns font for table cells
     * @see setContentFont
     * @see headerFont
     */
    QFont contentFont() const { return mContentFont; }

    /**Sets the color used to draw text in table body cells.
     * @param color table cell text color
     * @see contentFontColor
     * @see setContentFont
     * @see setHeaderFontColor
     */
    void setContentFontColor( const QColor& color );

    /**Returns the color used to draw text in table body cells.
     * @returns text color for table cells
     * @see setContentFontColor
     * @see contentFont
     * @see headerFontColor
     */
    QColor contentFontColor() const { return mContentFontColor; }

    /**Sets whether grid lines should be drawn in the table
     * @param showGrid set to true to show grid lines
     * @see showGrid
     * @see setGridStrokeWidth
     * @see setGridColor
     */
    void setShowGrid( const bool showGrid );

    /**Returns whether grid lines are drawn in the table
     * @returns true if grid lines are shown
     * @see setShowGrid
     * @see gridStrokeWidth
     * @see gridColor
     */
    bool showGrid() const { return mShowGrid; }

    /**Sets the width for grid lines in the table.
     * @param width grid line width
     * @see gridStrokeWidth
     * @see setShowGrid
     * @see setGridColor
     */
    void setGridStrokeWidth( const double width );

    /**Returns the width of grid lines in the table.
     * @returns grid line width
     * @see setGridStrokeWidth
     * @see showGrid
     * @see gridColor
     */
    double gridStrokeWidth() const { return mGridStrokeWidth; }

    /**Sets color used for grid lines in the table.
     * @param color grid line color
     * @see gridColor
     * @see setShowGrid
     * @see setGridStrokeWidth
     */
    void setGridColor( const QColor& color );

    /**Returns the color used for grid lines in the table.
     * @returns grid line color
     * @see setGridColor
     * @see showGrid
     * @see gridStrokeWidth
     */
    QColor gridColor() const { return mGridColor; }

    /**Returns a pointer to the list of QgsComposerTableColumns shown in the table
     * @returns pointer to list of columns in table
     * @see setColumns
     */
    QgsComposerTableColumns* columns() { return &mColumns; }

    /**Replaces the columns in the table with a specified list of QgsComposerTableColumns.
     * @param columns list of QgsComposerTableColumns to show in table
     * @see columns
     */
    void setColumns( QgsComposerTableColumns columns );

    /**Returns the text used in the column headers for the table.
     * @returns QMap of int to QString, where the int is the column index (starting at 0),
     * and the string is the text to use for the column's header
     * @note not available in python bindings
     */
    virtual QMap<int, QString> headerLabels() const;

    /**Fetches the contents used for the cells in the table.
     * @returns true if table contents were successfully retrieved.
     * @param contents QgsComposerTableContents to store retrieved row data in
     * @note not available in python bindings
     */
    virtual bool getTableContents( QgsComposerTableContents &contents ) = 0;

    //reimplemented to return fixed table width
    virtual QSizeF fixedFrameSize( const int frameIndex = -1 ) const;

    //reimplemented to return min frame height
    virtual QSizeF minFrameSize( const int frameIndex = -1 ) const;

  public slots:

    /**Refreshes the contents shown in the table by querying for new data.
     * This also causes the column widths and size of the table to change to accommodate the
     * new data.
     * @see adjustFrameToSize
    */
    virtual void refreshAttributes();

  protected:
    /**Margin between cell borders and cell text*/
    double mCellMargin;

    /**Header font*/
    QFont mHeaderFont;

    /**Header font color*/
    QColor mHeaderFontColor;

    /**Alignment for table headers*/
    HeaderHAlignment mHeaderHAlignment;

    /**Header display mode*/
    HeaderMode mHeaderMode;

    /**Table contents font*/
    QFont mContentFont;

    /**Table contents font color*/
    QColor mContentFontColor;

    /**True if grid should be shown*/
    bool mShowGrid;

    /**Width of grid lines*/
    double mGridStrokeWidth;

    /**Color for grid lines*/
    QColor mGridColor;

    /**Columns to show in table*/
    QgsComposerTableColumns mColumns;

    /**Contents to show in table*/
    QgsComposerTableContents mTableContents;

    /**Map of maximum width for each column*/
    QMap<int, double> mMaxColumnWidthMap;

    QSizeF mTableSize;

    /**Calculates the maximum width of text shown in columns.
     */
    virtual bool calculateMaxColumnWidths();

    //not const
    double totalWidth();

    double totalHeight() const;

    /**Calculates how many content rows are visible within a given frame
     * @param frameIndex index number for frame
     * @returns number of visible content rows (excludes header rows)
     */
    int rowsVisible( const int frameIndex ) const;

    /**Calculates a range of rows which should be visible in a given
     * rectangle.
     * @param extent visible extent
     * @param frameIndex index number for frame
     * @returns row range
     */
    QPair<int, int> rowRange( const QRectF extent, const int frameIndex ) const;


    /**Draws the horizontal grid lines for the table.
     * @param painter destination painter for grid lines
     * @param rows number of rows shown in table
     * @param drawHeaderLines set to true to include for the table header
     * @see drawVerticalGridLines
     */
    void drawHorizontalGridLines( QPainter* painter, const int rows, const bool drawHeaderLines ) const;

    /**Draws the vertical grid lines for the table.
     * @param painter destination painter for grid lines
     * @param maxWidthMap QMap of int to double, where the int contains the column number and the double is the
     * maximum width of text present in the column.
     * @param numberRows number of rows of content in table frame
     * @param hasHeader set to true if table frame includes header cells
     * @note not available in python bindings
     * @see drawVerticalGridLines
     * @see calculateMaxColumnWidths
     */
    void drawVerticalGridLines( QPainter* painter, const QMap<int, double>& maxWidthMap, const int numberRows, const bool hasHeader ) const;

    void adjustFrameToSize();
};

#endif // QGSCOMPOSERTABLEV2_H