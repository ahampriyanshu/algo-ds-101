var caesarEncypt = function(str, key) {

    if (key < 0) {
        return caesarEncypt(str, key + 26);
    }

    var encrypted = "";

    for (var i = 0; i < str.length; i++) {

        var c = str[i];

        if (c.match(/[a-z]/i)) {

            var code = str.charCodeAt(i);

            if (code >= 65 && code <= 90) {
                c = String.fromCharCode(((code - 65 + key) % 26) + 65);
            } else if (code >= 97 && code <= 122) {
                c = String.fromCharCode(((code - 97 + key) % 26) + 97);
            }
        }

        encrypted += c;
    }

    return encrypted;
};
