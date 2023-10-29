<!DOCTYPE html>
<html>
<head>
        <title>PHP Multiplication Table</title>
        <link rel="stylesheet" type="text/css" href="./css/practice1.css">
        <link href="https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;700&display=swap" rel="stylesheet">
    </head>
<body>
    <main>
        <div class="profile-card" style="width: 25vw;">
            <form method="post">
                Enter a number: <input type="number" name="number">
                <input type="submit" value="Generate Table">
            </form>
            <br>
            <?php
                if (isset($_POST['number'])) {
                    $num = intval($_POST['number']);
                    echo "<table border='1'>";
                    
                    echo "<tr><td></td>";
                    for ($col = 1; $col <= $num; $col++) {
                        echo "<td>$col</td>";
                    }
                    echo "</tr>";

                    for ($row = 1; $row <= $num; $row++) {
                        echo "<tr>";
                        
                        echo "<td>$row</td>";
                        
                        for ($col = 1; $col <= $num; $col++) {
                            echo "<td>" . ($row * $col) . "</td>";
                        }
                        echo "</tr>";
                    }
                    echo "</table>";
                }
            ?>
        </div>
    </main>

</body>
</html>
